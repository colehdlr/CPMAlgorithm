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

    /* Three-point (PERT) estimates. Default to `duration` for all three
     * when the input doesn't supply them, which makes pert_expected
     * collapse to `duration` and pert_variance collapse to 0. */
    int  optimistic, most_likely, pessimistic;
    double pert_expected;   /* (O + 4M + P) / 6 */
    double pert_variance;   /* ((P - O) / 6)^2 */
    double pert_stddev;

    int  deps[CPM_MAX_DEPS];
    int  num_deps;

    int  es, ef, ls, lf;
    int  total_float;   /* LS - ES (== LF - EF); slack against the project deadline */
    int  free_float;    /* min(successor ES) - EF; slack before delaying any successor */
    bool is_critical;

    int  topo_rank;
} Activity;

typedef struct {
    Activity *items;
    int       count;
    int       capacity;
    int      *topo_order;
    int       project_duration;

    /* PERT project-level summary, valid after pert_compute(). Expected
     * duration and variance are summed over the critical path found by
     * cpm_compute(). */
    double    project_pert_duration;
    double    project_variance;
    double    project_stddev;
} Graph;

void graph_init(Graph *graph);
void graph_free(Graph *graph);

/* On failure, prints an error to stderr and leaves *graph empty. */
bool graph_load_from_json(const char *path, Graph *graph);

/* Unique ids, non-negative durations, resolvable dependency ids. */
bool graph_validate(const Graph *graph);

/* Kahn's algorithm. Returns false on cycle.
 * Populates graph->topo_order and Activity.topo_rank (longest path from a source). */
bool graph_topological_sort(Graph *graph);

int graph_find_id(const Graph *graph, const char *id);

#endif
