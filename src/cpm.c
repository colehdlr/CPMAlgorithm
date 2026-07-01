#include "cpm.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Kahn's algorithm. Returns malloc'd order array (caller frees), NULL on cycle/OOM. */
static int *topological_sort(const Activity *activities, int count) {
    int *order = malloc((size_t)count * sizeof(int));
    if (!order) return NULL;

    int in_degree[count];
    for (int i = 0; i < count; ++i) in_degree[i] = activities[i].dep_count;

    int produced = 0;
    while (produced < count) {
        int picked = -1;
        for (int i = 0; i < count; ++i) {
            if (in_degree[i] == 0) { picked = i; break; }
        }
        if (picked < 0) {
            fprintf(stderr, "cpm: cycle in dependency graph\n");
            free(order);
            return NULL;
        }
        in_degree[picked] = -1;
        order[produced++] = picked;
        for (int j = 0; j < count; ++j) {
            for (int k = 0; k < activities[j].dep_count; ++k) {
                if (activities[j].deps[k] == picked) { in_degree[j]--; break; }
            }
        }
    }

    return order;
}

/* Rounded PERT expected duration, used as the activity's scheduling length. */
static int expected_duration(const Activity *a) {
    double e = (a->optimistic + 4.0 * a->most_likely + a->pessimistic) / 6.0;
    return (int)lround(e);
}

CPMResult *cpm_compute(const Activity *activities, int count) {
    if (count <= 0) return NULL;

    int *order = topological_sort(activities, count);
    if (!order) return NULL;

    CPMResult *results = calloc((size_t)count, sizeof(CPMResult));
    if (!results) { free(order); return NULL; }

    /* Forward pass: ES/EF in topological order. */
    for (int pos = 0; pos < count; ++pos) {
        int idx = order[pos];
        const Activity *a = &activities[idx];
        int es = 0;
        for (int k = 0; k < a->dep_count; ++k) {
            int ef = results[a->deps[k]].earliest_finish;
            if (ef > es) es = ef;
        }
        results[idx].earliest_start  = es;
        results[idx].earliest_finish = es + expected_duration(a);
    }

    int project_duration = 0;
    for (int i = 0; i < count; ++i) {
        if (results[i].earliest_finish > project_duration) {
            project_duration = results[i].earliest_finish;
        }
    }
    /* Backward pass: reverse topo order, push each node's LS into preds' LF as a min. */
    for (int i = 0; i < count; ++i) results[i].latest_finish = project_duration;
    for (int pos = count - 1; pos >= 0; --pos) {
        int idx = order[pos];
        const Activity *a = &activities[idx];
        results[idx].latest_start = results[idx].latest_finish - expected_duration(a);
        results[idx].total_float  = results[idx].latest_start - results[idx].earliest_start;
        for (int k = 0; k < a->dep_count; ++k) {
            CPMResult *pr = &results[a->deps[k]];
            if (results[idx].latest_start < pr->latest_finish) {
                pr->latest_finish = results[idx].latest_start;
            }
        }
    }

    /* Free float: min(ES of successors) - EF. Tail activities default to
     * project_duration - EF, which equals their total float. */
    for (int i = 0; i < count; ++i) {
        results[i].free_float = project_duration - results[i].earliest_finish;
    }
    for (int i = 0; i < count; ++i) {
        const Activity *a = &activities[i];
        for (int k = 0; k < a->dep_count; ++k) {
            int p = a->deps[k];
            int candidate = results[i].earliest_start - results[p].earliest_finish;
            if (candidate < results[p].free_float) {
                results[p].free_float = candidate;
            }
        }
    }

    free(order);
    return results;
}

PERTSummary pert_compute(const Activity *activities, CPMResult *results, int count) {
    PERTSummary summary = { 0 };
    if (count <= 0) return summary;

    for (int i = 0; i < count; ++i) {
        const Activity *a = &activities[i];
        CPMResult *r = &results[i];
        double spread = (a->pessimistic - a->optimistic) / 6.0;
        r->pert_expected = (a->optimistic + 4.0 * a->most_likely + a->pessimistic) / 6.0;
        r->pert_variance = spread * spread;
        r->pert_stddev   = sqrt(r->pert_variance);
    }

    /* Expected duration and variance of the whole project are the sum of
     * the per-activity values along the critical path (variances of
     * independent activities add; standard deviations don't). */
    double expected = 0.0, variance = 0.0;
    for (int i = 0; i < count; ++i) {
        if (results[i].total_float != 0) continue;
        expected += results[i].pert_expected;
        variance += results[i].pert_variance;
    }

    summary.project_pert_duration = expected;
    summary.project_variance = variance;
    summary.project_stddev = sqrt(variance);
    return summary;
}

void pert_print_table(const Activity *activities, const CPMResult *results,
                       int count, PERTSummary summary) {
    if (count <= 0) { printf("(empty graph)\n"); return; }

    int id_width = 2, name_width = 4;
    for (int i = 0; i < count; ++i) {
        int name_len = (int)strlen(activities[i].name);
        if (name_len > name_width) name_width = name_len;
    }

    printf("\n%-*s  %-*s  %4s  %4s  %4s  %8s  %6s  %s\n",
           id_width, "ID", name_width, "Name", "O", "M", "P", "Expected", "StdDev", "Crit");
    int dash_len = id_width + name_width + 42;
    for (int i = 0; i < dash_len; ++i) putchar('-');
    putchar('\n');

    for (int i = 0; i < count; ++i) {
        const Activity  *a = &activities[i];
        const CPMResult *r = &results[i];
        printf("%-*c  %-*s  %4d  %4d  %4d  %8.2f  %6.2f  %s\n",
               id_width, a->id, name_width, a->name,
               a->optimistic, a->most_likely, a->pessimistic,
               r->pert_expected, r->pert_stddev,
               r->total_float == 0 ? "*" : "");
    }

    double low  = summary.project_pert_duration - 1.96 * summary.project_stddev;
    double high = summary.project_pert_duration + 1.96 * summary.project_stddev;
    printf("\nPERT expected duration: %.2f  (variance %.2f, stddev %.2f)\n"
           "95%% confidence interval: [%.2f, %.2f]\n\n",
           summary.project_pert_duration, summary.project_variance, summary.project_stddev,
           low, high);
}
