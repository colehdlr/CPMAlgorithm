#ifndef RENDER_H
#define RENDER_H

#include "types.h"
#include "cpm.h"

/* Open a window, lay nodes out by topological rank, draw edges and CPM cards.
 * Critical path is highlighted. Drag to pan, wheel to zoom, R to reset, ESC to quit. */
void render_run(const Activity *activities, int count,
                const int *topo_order,
                const CPMResult *results, int project_duration);

#endif /* RENDER_H */
