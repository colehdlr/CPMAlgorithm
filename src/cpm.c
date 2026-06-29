#include "cpm.h"

#include <stdio.h>
#include <string.h>

bool cpm_compute(Graph *graph) {
    if (!graph || graph->count <= 0 || !graph->topo_order) return false;
    int count = graph->count;

    /* Forward pass: ES/EF in topological order. */
    int project_duration = 0;
    for (int i = 0; i < count; ++i) {
        Activity *activity = &graph->items[graph->topo_order[i]];
        int earliest_start = 0;
        for (int k = 0; k < activity->num_deps; ++k) {
            int pred_finish = graph->items[activity->deps[k]].ef;
            if (pred_finish > earliest_start) earliest_start = pred_finish;
        }
        activity->es = earliest_start;
        activity->ef = earliest_start + activity->duration;
        if (activity->ef > project_duration) project_duration = activity->ef;
    }
    graph->project_duration = project_duration;

    /* Backward pass: initialise lf to project_duration, then walk reverse
     * topological order and push each node's ls into its predecessors' lf
     * as a min. Sinks keep project_duration; every other node is updated
     * before it is read because its successors are processed first. This
     * avoids materialising a successor adjacency. */
    for (int i = 0; i < count; ++i) graph->items[i].lf = project_duration;
    for (int i = count - 1; i >= 0; --i) {
        Activity *activity = &graph->items[graph->topo_order[i]];
        activity->ls = activity->lf - activity->duration;
        activity->slack = activity->ls - activity->es;
        activity->is_critical = (activity->slack == 0);
        for (int k = 0; k < activity->num_deps; ++k) {
            Activity *predecessor = &graph->items[activity->deps[k]];
            if (activity->ls < predecessor->lf) predecessor->lf = activity->ls;
        }
    }
    return true;
}

void cpm_print_table(const Graph *graph) {
    if (!graph || graph->count <= 0) { printf("(empty graph)\n"); return; }

    int id_width = 2, name_width = 4;
    for (int i = 0; i < graph->count; ++i) {
        int id_len   = (int)strlen(graph->items[i].id);
        int name_len = (int)strlen(graph->items[i].name);
        if (id_len   > id_width)   id_width   = id_len;
        if (name_len > name_width) name_width = name_len;
    }

    printf("\n%-*s  %-*s  %5s  %4s  %4s  %4s  %4s  %5s  %s\n",
           id_width, "ID", name_width, "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    int dash_len = id_width + name_width + 36;
    for (int i = 0; i < dash_len; ++i) putchar('-');
    putchar('\n');

    for (int i = 0; i < graph->count; ++i) {
        int index = graph->topo_order ? graph->topo_order[i] : i;
        const Activity *activity = &graph->items[index];
        printf("%-*s  %-*s  %5d  %4d  %4d  %4d  %4d  %5d  %s\n",
               id_width, activity->id, name_width, activity->name,
               activity->duration, activity->es, activity->ef,
               activity->ls, activity->lf, activity->slack,
               activity->is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", graph->project_duration);
}
