#include "cpm.h"

#include <math.h>
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
        activity->total_float = activity->ls - activity->es;
        activity->is_critical = (activity->total_float == 0);
        for (int k = 0; k < activity->num_deps; ++k) {
            Activity *predecessor = &graph->items[activity->deps[k]];
            if (activity->ls < predecessor->lf) predecessor->lf = activity->ls;
        }
    }

    /* Free float: how far an activity can slip without delaying any
     * successor's earliest start (tighter than total float, which only
     * guards the project deadline). Sinks compare against project_duration
     * since they have no successor to constrain them. */
    for (int i = 0; i < count; ++i) {
        int min_successor_es = project_duration;
        for (int j = 0; j < count; ++j) {
            for (int k = 0; k < graph->items[j].num_deps; ++k) {
                if (graph->items[j].deps[k] == i && graph->items[j].es < min_successor_es) {
                    min_successor_es = graph->items[j].es;
                }
            }
        }
        graph->items[i].free_float = min_successor_es - graph->items[i].ef;
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

    printf("\n%-*s  %-*s  %5s  %4s  %4s  %4s  %4s  %5s  %5s  %s\n",
           id_width, "ID", name_width, "Name", "Dur", "ES", "EF", "LS", "LF", "TF", "FF", "Crit");
    int dash_len = id_width + name_width + 42;
    for (int i = 0; i < dash_len; ++i) putchar('-');
    putchar('\n');

    for (int i = 0; i < graph->count; ++i) {
        int index = graph->topo_order ? graph->topo_order[i] : i;
        const Activity *activity = &graph->items[index];
        printf("%-*s  %-*s  %5d  %4d  %4d  %4d  %4d  %5d  %5d  %s\n",
               id_width, activity->id, name_width, activity->name,
               activity->duration, activity->es, activity->ef,
               activity->ls, activity->lf, activity->total_float, activity->free_float,
               activity->is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", graph->project_duration);
}

void pert_compute(Graph *graph) {
    if (!graph || graph->count <= 0) return;

    for (int i = 0; i < graph->count; ++i) {
        Activity *activity = &graph->items[i];
        double spread = (activity->pessimistic - activity->optimistic) / 6.0;
        activity->pert_expected = (activity->optimistic + 4.0 * activity->most_likely
                                   + activity->pessimistic) / 6.0;
        activity->pert_variance = spread * spread;
        activity->pert_stddev   = sqrt(activity->pert_variance);
    }

    /* Expected duration and variance of the whole project are the sum of
     * the per-activity values along the critical path (variances of
     * independent activities add; standard deviations don't). */
    double expected = 0.0, variance = 0.0;
    for (int i = 0; i < graph->count; ++i) {
        const Activity *activity = &graph->items[i];
        if (!activity->is_critical) continue;
        expected += activity->pert_expected;
        variance += activity->pert_variance;
    }

    graph->project_pert_duration = expected;
    graph->project_variance = variance;
    graph->project_stddev = sqrt(variance);
}

void pert_print_table(const Graph *graph) {
    if (!graph || graph->count <= 0) { printf("(empty graph)\n"); return; }

    int id_width = 2, name_width = 4;
    for (int i = 0; i < graph->count; ++i) {
        int id_len   = (int)strlen(graph->items[i].id);
        int name_len = (int)strlen(graph->items[i].name);
        if (id_len   > id_width)   id_width   = id_len;
        if (name_len > name_width) name_width = name_len;
    }

    printf("\n%-*s  %-*s  %4s  %4s  %4s  %8s  %6s  %s\n",
           id_width, "ID", name_width, "Name", "O", "M", "P", "Expected", "StdDev", "Crit");
    int dash_len = id_width + name_width + 42;
    for (int i = 0; i < dash_len; ++i) putchar('-');
    putchar('\n');

    for (int i = 0; i < graph->count; ++i) {
        int index = graph->topo_order ? graph->topo_order[i] : i;
        const Activity *activity = &graph->items[index];
        printf("%-*s  %-*s  %4d  %4d  %4d  %8.2f  %6.2f  %s\n",
               id_width, activity->id, name_width, activity->name,
               activity->optimistic, activity->most_likely, activity->pessimistic,
               activity->pert_expected, activity->pert_stddev,
               activity->is_critical ? "*" : "");
    }

    double low  = graph->project_pert_duration - 1.96 * graph->project_stddev;
    double high = graph->project_pert_duration + 1.96 * graph->project_stddev;
    printf("\nPERT expected duration: %.2f  (variance %.2f, stddev %.2f)\n"
           "95%% confidence interval: [%.2f, %.2f]\n\n",
           graph->project_pert_duration, graph->project_variance, graph->project_stddev,
           low, high);
}
