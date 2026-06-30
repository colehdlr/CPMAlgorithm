#include "cpm.h"

#include <stdio.h>
#include <stdlib.h>

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
        results[idx].earliest_finish = es + a->duration;
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
        results[idx].latest_start = results[idx].latest_finish - a->duration;
        results[idx].total_float  = results[idx].latest_start - results[idx].earliest_start;
        for (int k = 0; k < a->dep_count; ++k) {
            CPMResult *pr = &results[a->deps[k]];
            if (results[idx].latest_start < pr->latest_finish) {
                pr->latest_finish = results[idx].latest_start;
            }
        }
    }

    free(order);
    return results;
}
