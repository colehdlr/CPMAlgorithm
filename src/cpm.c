#include "cpm.h"

#include <stdio.h>
#include <stdlib.h>

static bool topological_sort(const Activity *items, int count, int **out_order) {
    int *in_degree = malloc((size_t)count * sizeof(int));
    int *order     = malloc((size_t)count * sizeof(int));
    if (!in_degree || !order) { free(in_degree); free(order); return false; }

    for (int i = 0; i < count; ++i) in_degree[i] = items[i].dep_count;

    int produced = 0;
    while (produced < count) {
        int picked = -1;
        for (int i = 0; i < count; ++i) {
            if (in_degree[i] == 0) { picked = i; break; }
        }
        if (picked < 0) {
            fprintf(stderr, "cpm: cycle detected\n");
            free(in_degree); free(order);
            return false;
        }
        in_degree[picked] = -1;
        order[produced++] = picked;
        for (int j = 0; j < count; ++j) {
            for (int k = 0; k < items[j].dep_count; ++k) {
                if (find_activity(items, count, items[j].deps_on_ids[k]) == picked) {
                    in_degree[j]--;
                    break;
                }
            }
        }
    }

    *out_order = order;
    free(in_degree);
    return true;
}

bool cpm_compute(const Activity *items, int count,
                 CPMResult *results, int *project_duration) {
    if (count <= 0) return false;

    int *topo_order = NULL;
    if (!topological_sort(items, count, &topo_order)) return false;

    /* Forward pass: ES/EF in topological order. */
    *project_duration = 0;
    for (int i = 0; i < count; ++i) {
        int idx = topo_order[i];
        const Activity *a = &items[idx];
        int es = 0;
        for (int k = 0; k < a->dep_count; ++k) {
            int p = find_activity(items, count, a->deps_on_ids[k]);
            int pf = results[p].earliest_finish;
            if (pf > es) es = pf;
        }
        results[idx].earliest_start  = es;
        results[idx].earliest_finish = es + a->duration;
        if (results[idx].earliest_finish > *project_duration)
            *project_duration = results[idx].earliest_finish;
    }

    /* Backward pass: walk reverse topo order. */
    for (int i = 0; i < count; ++i) results[i].latest_finish = *project_duration;
    for (int i = count - 1; i >= 0; --i) {
        int idx = topo_order[i];
        const Activity *a = &items[idx];
        results[idx].latest_start = results[idx].latest_finish - a->duration;
        results[idx].total_float  = results[idx].latest_start - results[idx].earliest_start;
        for (int k = 0; k < a->dep_count; ++k) {
            int p = find_activity(items, count, a->deps_on_ids[k]);
            if (results[idx].latest_start < results[p].latest_finish)
                results[p].latest_finish = results[idx].latest_start;
        }
    }

    /* Free float: min(ES of successors) - EF of current. */
    for (int i = 0; i < count; ++i) {
        int min_succ_es = *project_duration;
        for (int j = 0; j < count; ++j) {
            for (int k = 0; k < items[j].dep_count; ++k) {
                if (find_activity(items, count, items[j].deps_on_ids[k]) == i) {
                    if (results[j].earliest_start < min_succ_es)
                        min_succ_es = results[j].earliest_start;
                }
            }
        }
        results[i].free_float = min_succ_es - results[i].earliest_finish;
    }

    free(topo_order);
    return true;
}

void cpm_print_table(const Activity *items, const CPMResult *results,
                     int count, int project_duration) {
    printf("\n%-4s  %-22s  %4s  %4s  %4s  %4s  %4s  %5s  %s\n",
           "ID", "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        const Activity *a = &items[i];
        const CPMResult *r = &results[i];
        bool is_critical = (r->total_float == 0);
        printf("%-4c  %-22s  %4d  %4d  %4d  %4d  %4d  %5d  %s\n",
               a->id, a->name, a->duration,
               r->earliest_start, r->earliest_finish,
               r->latest_start, r->latest_finish, r->total_float,
               is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", project_duration);
}
