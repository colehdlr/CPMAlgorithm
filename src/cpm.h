#ifndef CPM_H
#define CPM_H

#include <stdbool.h>

#include "parse.h"

typedef struct {
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
    int free_float;
    int total_float;
} CPMResult;

bool cpm_compute(const Activity *items, int count, const int *topo_order,
                 CPMResult *results, int *project_duration);

void cpm_print_table(const Activity *items, const CPMResult *results,
                     int count, const int *topo_order, int project_duration);

#endif
