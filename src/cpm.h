#ifndef CPM_H
#define CPM_H

#include <stdbool.h>

#include "types.h"

typedef struct {
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
    int total_float;
} CPMResult;

/* Run forward + backward passes over a topologically sorted graph.
 * Caller supplies a `results` array of length `count`. On success,
 * fills `results` and writes the project duration to *out_project_duration. */
bool cpm_compute(const Activity *activities, int count,
                 const int *topo_order,
                 CPMResult *results, int *out_project_duration);

/* Print id, name, duration, ES, EF, LS, LF, slack, and a critical marker. */
void cpm_print_table(const Activity *activities, int count,
                     const int *topo_order,
                     const CPMResult *results, int project_duration);

#endif /* CPM_H */
