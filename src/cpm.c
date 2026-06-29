#include "cpm.h"

#include <stdio.h>

bool cpm_compute(const Activity *items, int count, const int *topo_order,
                 CPMResult *results, int *project_duration) {
    if (count <= 0 || !topo_order) return false;

    /* Forward pass: ES/EF in topological order. */
    int pd = 0;
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
        if (results[idx].earliest_finish > pd) pd = results[idx].earliest_finish;
    }
    *project_duration = pd;

    /* Backward pass: walk reverse topo order. */
    for (int i = 0; i < count; ++i) results[i].latest_finish = pd;
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

    return true;
}

void cpm_print_table(const Activity *items, const CPMResult *results,
                     int count, const int *topo_order, int project_duration) {
    printf("\n%-4s  %-22s  %4s  %4s  %4s  %4s  %4s  %5s  %s\n",
           "ID", "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        int idx = topo_order ? topo_order[i] : i;
        const Activity *a = &items[idx];
        const CPMResult *r = &results[idx];
        bool is_critical = (r->total_float == 0);
        printf("%-4c  %-22s  %4d  %4d  %4d  %4d  %4d  %5d  %s\n",
               a->id, a->name, a->duration,
               r->earliest_start, r->earliest_finish,
               r->latest_start, r->latest_finish, r->total_float,
               is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", project_duration);
}
