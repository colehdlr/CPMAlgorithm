#include "cpm.h"

#include <stdio.h>

bool cpm_compute(const Activity *activities, int count,
                 const int *topo_order,
                 CPMResult *results, int *out_project_duration) {
    if (count <= 0 || !topo_order || !results) return false;

    /* Forward pass: ES/EF in topological order. */
    int project_duration = 0;
    for (int i = 0; i < count; ++i) {
        int idx = topo_order[i];
        const Activity *a = &activities[idx];
        int es = 0;
        for (int k = 0; k < a->dep_count; ++k) {
            int pf = results[a->deps[k]].earliest_finish;
            if (pf > es) es = pf;
        }
        results[idx].earliest_start  = es;
        results[idx].earliest_finish = es + a->duration;
        if (results[idx].earliest_finish > project_duration) {
            project_duration = results[idx].earliest_finish;
        }
    }
    *out_project_duration = project_duration;

    /* Backward pass: walk reverse topo order, pushing each node's LS
     * into its predecessors' LF as a min. */
    for (int i = 0; i < count; ++i) results[i].latest_finish = project_duration;
    for (int i = count - 1; i >= 0; --i) {
        int idx = topo_order[i];
        const Activity *a = &activities[idx];
        CPMResult *r = &results[idx];
        r->latest_start = r->latest_finish - a->duration;
        r->total_float  = r->latest_start - r->earliest_start;
        for (int k = 0; k < a->dep_count; ++k) {
            CPMResult *p = &results[a->deps[k]];
            if (r->latest_start < p->latest_finish) p->latest_finish = r->latest_start;
        }
    }
    return true;
}

void cpm_print_table(const Activity *activities, int count,
                     const int *topo_order,
                     const CPMResult *results, int project_duration) {
    printf("\n%-3s  %-22s  %4s  %4s  %4s  %4s  %4s  %5s  %s\n",
           "ID", "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        int idx = topo_order ? topo_order[i] : i;
        const Activity  *a = &activities[idx];
        const CPMResult *r = &results[idx];
        bool critical = (r->total_float == 0);
        printf("%-3c  %-22s  %4d  %4d  %4d  %4d  %4d  %5d  %s\n",
               a->id, a->name, a->duration,
               r->earliest_start, r->earliest_finish,
               r->latest_start, r->latest_finish, r->total_float,
               critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", project_duration);
}
