#ifndef RENDER_H
#define RENDER_H

#include "parse.h"
#include "cpm.h"

void render_run(const Activity *items, const CPMResult *results,
                int count, const int *topo_order, int project_duration);

#endif
