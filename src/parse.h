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
} Activity;

typedef struct {
    Activity *items;
    int       count;
    int      *topo_order;
    int       project_duration;
} Graph;

void graph_init(Graph *graph);
void graph_free(Graph *graph);

/* Loads, validates (non-empty unique ids, non-negative durations, resolvable
 * deps) and stores the graph. On failure, prints an error to stderr and leaves
 * *graph empty. */
bool graph_load_from_json(const char *path, Graph *graph);

/* Kahn's algorithm. Returns false on cycle. Populates graph->topo_order. */
bool graph_topological_sort(Graph *graph);

int graph_find_id(const Graph *graph, const char *id);

#endif
