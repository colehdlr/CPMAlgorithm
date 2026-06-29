#ifndef RENDER_H
#define RENDER_H

#include "parse.h"
#include "cpm.h"

void render_run(const Activity *items, const CPMResult *results,
                int count, int project_duration);

#endif
