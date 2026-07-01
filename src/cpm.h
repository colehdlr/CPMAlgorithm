#ifndef CPM_H
#define CPM_H

#include <stdbool.h>

#include "parse.h"

/* Run forward + backward passes over a topologically sorted graph,
 * populating es/ef/ls/lf/total_float/free_float/is_critical and
 * graph->project_duration. */
bool cpm_compute(Graph *graph);

/* Print id, name, duration, ES, EF, LS, LF, total float, free float, and a
 * critical marker. */
void cpm_print_table(const Graph *graph);

/* PERT three-point estimation. For every activity, computes:
 *   pert_expected = (optimistic + 4*most_likely + pessimistic) / 6
 *   pert_variance = ((pessimistic - optimistic) / 6)^2
 * Then sums expected time and variance over the critical path (as found
 * by cpm_compute) into graph->project_pert_duration/variance/stddev.
 * Requires cpm_compute() to have run first so is_critical is populated. */
void pert_compute(Graph *graph);

/* Print per-activity O/M/P/expected/stddev plus the project-level PERT
 * expected duration and a 95% confidence interval (+/- 1.96 stddev). */
void pert_print_table(const Graph *graph);

#endif
