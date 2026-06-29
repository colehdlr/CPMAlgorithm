#include "cpm.h"

#include <stdio.h>

bool cpm_compute(const Activity *activities, int count,
                 const int *topo_order,
                 CPMResult *results, int *out_project_duration) {
    if (count <= 0 || !topo_order || !results) return false;

    /* Forward pass: ES/EF in topological order. */
    int project_duration = 0;
    for (int topo_pos = 0; topo_pos < count; ++topo_pos) {
        int activity_index = topo_order[topo_pos];
        const Activity *activity = &activities[activity_index];
        CPMResult *result = &results[activity_index];

        int earliest_start = 0;
        for (int dep_slot = 0; dep_slot < activity->dep_count; ++dep_slot) {
            int predecessor_finish = results[activity->deps[dep_slot]].earliest_finish;
            if (predecessor_finish > earliest_start) earliest_start = predecessor_finish;
        }
        result->earliest_start  = earliest_start;
        result->earliest_finish = earliest_start + activity->duration;

        if (result->earliest_finish > project_duration) {
            project_duration = result->earliest_finish;
        }
    }
    *out_project_duration = project_duration;

    /* Backward pass: walk reverse topo order, pushing each node's LS
     * into its predecessors' LF as a min. */
    for (int index = 0; index < count; ++index) {
        results[index].latest_finish = project_duration;
    }
    for (int topo_pos = count - 1; topo_pos >= 0; --topo_pos) {
        int activity_index = topo_order[topo_pos];
        const Activity *activity = &activities[activity_index];
        CPMResult *result = &results[activity_index];

        result->latest_start = result->latest_finish - activity->duration;
        result->total_float  = result->latest_start - result->earliest_start;

        for (int dep_slot = 0; dep_slot < activity->dep_count; ++dep_slot) {
            CPMResult *predecessor_result = &results[activity->deps[dep_slot]];
            if (result->latest_start < predecessor_result->latest_finish) {
                predecessor_result->latest_finish = result->latest_start;
            }
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
    for (int topo_pos = 0; topo_pos < count; ++topo_pos) {
        int activity_index = topo_order ? topo_order[topo_pos] : topo_pos;
        const Activity  *activity = &activities[activity_index];
        const CPMResult *result   = &results[activity_index];
        bool critical = (result->total_float == 0);
        printf("%-3c  %-22s  %4d  %4d  %4d  %4d  %4d  %5d  %s\n",
               activity->id, activity->name, activity->duration,
               result->earliest_start, result->earliest_finish,
               result->latest_start, result->latest_finish, result->total_float,
               critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", project_duration);
}
