#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>

#define CPM_MAX_ID_LEN    32
#define CPM_MAX_NAME_LEN  128
#define CPM_MAX_DEPS      32

/* One struct holds input fields and CPM results so every module shares
 * the same representation without conversions. */
typedef struct {
    char id[CPM_MAX_ID_LEN];
    char name[CPM_MAX_NAME_LEN];
    int  duration;

    int  deps[CPM_MAX_DEPS];
    int  num_deps;

    int  es, ef, ls, lf, slack;
    bool is_critical;

    int  topo_rank;
} Activity;

typedef struct {
    Activity *items;
    int       count;
    int       capacity;
    int      *topo_order;
    int       project_duration;
} Graph;

void graph_init(Graph *g);
void graph_free(Graph *g);

/* On failure, prints an error to stderr and leaves *g empty. */
bool graph_load_from_json(const char *path, Graph *g);

/* Unique ids, non-negative durations, resolvable dependency ids. */
bool graph_validate(const Graph *g);

/* Kahn's algorithm. Returns false on cycle.
 * Populates g->topo_order and Activity.topo_rank (longest path from a source). */
bool graph_topological_sort(Graph *g);

int graph_find_id(const Graph *g, const char *id);

#endif
