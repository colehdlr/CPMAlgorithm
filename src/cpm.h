#ifndef CPM_H
#define CPM_H

#include <stdbool.h>

#include "parse.h"

/* Run forward + backward passes over a topologically sorted graph,
 * populating es/ef/ls/lf/slack/is_critical and g->project_duration. */
bool cpm_compute(Graph *g);

/* Print id, name, duration, ES, EF, LS, LF, slack, and a critical marker. */
void cpm_print_table(const Graph *g);

#endif
