#include "cpm.h"

#include <stdio.h>

bool cpm_compute(Graph *graph) {
    if (graph->count <= 0 || !graph->topo_order) return false;
    int count = graph->count;

    /* Forward pass: ES/EF in topological order. */
    int project_duration = 0;
    for (int i = 0; i < count; ++i) {
        Activity *a = &graph->items[graph->topo_order[i]];
        int es = 0;
        for (int k = 0; k < a->num_deps; ++k) {
            int pf = graph->items[a->deps[k]].ef;
            if (pf > es) es = pf;
        }
        a->es = es;
        a->ef = es + a->duration;
        if (a->ef > project_duration) project_duration = a->ef;
    }
    graph->project_duration = project_duration;

    /* Backward pass: walk reverse topo order, pushing each node's ls
     * into its predecessors' lf as a min. */
    for (int i = 0; i < count; ++i) graph->items[i].lf = project_duration;
    for (int i = count - 1; i >= 0; --i) {
        Activity *a = &graph->items[graph->topo_order[i]];
        a->ls = a->lf - a->duration;
        a->slack = a->ls - a->es;
        a->is_critical = (a->slack == 0);
        for (int k = 0; k < a->num_deps; ++k) {
            Activity *p = &graph->items[a->deps[k]];
            if (a->ls < p->lf) p->lf = a->ls;
        }
    }
    return true;
}

void cpm_print_table(const Graph *graph) {
    printf("\n%-4s  %-22s  %4s  %4s  %4s  %4s  %4s  %5s  %s\n",
           "ID", "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < graph->count; ++i) {
        int idx = graph->topo_order ? graph->topo_order[i] : i;
        const Activity *a = &graph->items[idx];
        printf("%-4s  %-22s  %4d  %4d  %4d  %4d  %4d  %5d  %s\n",
               a->id, a->name, a->duration, a->es, a->ef, a->ls, a->lf, a->slack,
               a->is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", graph->project_duration);
}
