#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "cpm.h"

/*
 * Minimal self-contained test driver for parse + cpm.
 *
 * Builds a small graph in memory (no JSON), runs validation / topological sort
 * / CPM, and asserts the expected ES/EF/LS/LF/total_float/free_float/critical
 * values.
 *
 * Run with `make test`.
 */

static int add_activity(Graph *g, const char *id, const char *name, int duration,
                        const int *deps, int num_deps) {
    /* grow capacity by hand, mirroring parse.c's ensure_capacity */
    if (g->capacity <= g->count) {
        int new_cap = g->capacity ? g->capacity * 2 : 8;
        Activity *p = (Activity *)realloc(g->items, (size_t)new_cap * sizeof(Activity));
        if (!p) { fprintf(stderr, "oom\n"); exit(1); }
        g->items = p;
        g->capacity = new_cap;
    }
    Activity *a = &g->items[g->count];
    memset(a, 0, sizeof(*a));
    snprintf(a->id, sizeof(a->id), "%s", id);
    snprintf(a->name, sizeof(a->name), "%s", name);
    a->duration = duration;
    a->num_deps = num_deps;
    for (int i = 0; i < num_deps; ++i) a->deps[i] = deps[i];
    return g->count++;
}

static void test_textbook_network(void) {
    /* Same shape as data/activities.json so the test mirrors the demo. */
    Graph g; graph_init(&g);
    int A = add_activity(&g, "A", "Requirements",   3, NULL, 0);
    (void)A;
    int B = add_activity(&g, "B", "Design",         4, (int[]){0}, 1);
    int C = add_activity(&g, "C", "Database",       5, (int[]){0}, 1);
    int D = add_activity(&g, "D", "Frontend",       6, (int[]){B}, 1);
    int E = add_activity(&g, "E", "Backend",        7, (int[]){C}, 1);
    int F = add_activity(&g, "F", "Integration",    3, (int[]){D, E}, 2);
    int G = add_activity(&g, "G", "Testing",        4, (int[]){F}, 1);
    (void)G;

    assert(graph_validate(&g));
    assert(graph_topological_sort(&g));
    assert(cpm_compute(&g));

    assert(g.project_duration == 22);

    /* Spot-check each activity. Free float is tighter than total float for
     * B and D: both can slip 2 days without blowing the deadline (total
     * float), but D feeds F on its own, so D's own float (2) is genuine
     * free float, while B feeds only D, so any slip in B immediately
     * delays D's earliest start (free float 0). */
    struct { const char *id; int es, ef, ls, lf, total_float, free_float; int crit; } expected[] = {
        { "A", 0,  3,  0,  3, 0, 0, 1 },
        { "B", 3,  7,  5,  9, 2, 0, 0 },
        { "C", 3,  8,  3,  8, 0, 0, 1 },
        { "D", 7, 13,  9, 15, 2, 2, 0 },
        { "E", 8, 15,  8, 15, 0, 0, 1 },
        { "F",15, 18, 15, 18, 0, 0, 1 },
        { "G",18, 22, 18, 22, 0, 0, 1 },
    };
    for (size_t i = 0; i < sizeof(expected)/sizeof(expected[0]); ++i) {
        int idx = graph_find_id(&g, expected[i].id);
        assert(idx >= 0);
        const Activity *a = &g.items[idx];
        if (a->es != expected[i].es || a->ef != expected[i].ef
            || a->ls != expected[i].ls || a->lf != expected[i].lf
            || a->total_float != expected[i].total_float
            || a->free_float != expected[i].free_float
            || a->is_critical != (bool)expected[i].crit) {
            fprintf(stderr,
                "mismatch on %s: got ES=%d EF=%d LS=%d LF=%d TF=%d FF=%d crit=%d\n"
                "           want ES=%d EF=%d LS=%d LF=%d TF=%d FF=%d crit=%d\n",
                a->id, a->es, a->ef, a->ls, a->lf, a->total_float, a->free_float, (int)a->is_critical,
                expected[i].es, expected[i].ef, expected[i].ls, expected[i].lf,
                expected[i].total_float, expected[i].free_float, expected[i].crit);
            abort();
        }
    }
    graph_free(&g);
    printf("  ok  textbook_network\n");
}

static void test_single_activity(void) {
    Graph g; graph_init(&g);
    add_activity(&g, "X", "Only",  5, NULL, 0);

    assert(graph_validate(&g));
    assert(graph_topological_sort(&g));
    assert(cpm_compute(&g));

    assert(g.project_duration == 5);
    assert(g.items[0].es == 0 && g.items[0].ef == 5);
    assert(g.items[0].ls == 0 && g.items[0].lf == 5);
    assert(g.items[0].total_float == 0);
    assert(g.items[0].free_float == 0);
    assert(g.items[0].is_critical);

    graph_free(&g);
    printf("  ok  single_activity\n");
}

static void test_parallel_paths(void) {
    /* Two parallel chains from S to T:
     *     S(2) -> A(5) -> T(1)        path = 8 (critical)
     *     S(2) -> B(3) -> T(1)        path = 6
     *
     * A is critical, B is not (total float 2). B's only successor is T, and
     * T's ES is already pinned by A, so B can also slip its full 2 days
     * without moving T's ES: free float equals total float here.
     */
    Graph g; graph_init(&g);
    int S = add_activity(&g, "S", "Start", 2, NULL, 0);
    int A = add_activity(&g, "A", "A",     5, (int[]){S}, 1);
    int B = add_activity(&g, "B", "B",     3, (int[]){S}, 1);
    int T = add_activity(&g, "T", "End",   1, (int[]){A, B}, 2);
    (void)T;

    assert(graph_validate(&g));
    assert(graph_topological_sort(&g));
    assert(cpm_compute(&g));

    assert(g.project_duration == 8);
    assert(g.items[graph_find_id(&g, "A")].is_critical);
    assert(!g.items[graph_find_id(&g, "B")].is_critical);
    assert(g.items[graph_find_id(&g, "B")].total_float == 2);
    assert(g.items[graph_find_id(&g, "B")].free_float == 2);

    graph_free(&g);
    printf("  ok  parallel_paths\n");
}

static void test_cycle_rejected(void) {
    /* A -> B -> A is a cycle; topological sort must fail. */
    Graph g; graph_init(&g);
    int A = add_activity(&g, "A", "A", 1, (int[]){1}, 1);   /* will reference B */
    int B = add_activity(&g, "B", "B", 1, (int[]){A}, 1);
    (void)B;

    assert(graph_validate(&g));               /* validate doesn't check cycles */
    assert(!graph_topological_sort(&g));      /* cycle should be detected      */

    graph_free(&g);
    printf("  ok  cycle_rejected\n");
}

static void test_duplicate_ids_rejected(void) {
    Graph g; graph_init(&g);
    add_activity(&g, "X", "first", 1, NULL, 0);
    add_activity(&g, "X", "again", 1, NULL, 0);

    assert(!graph_validate(&g));

    graph_free(&g);
    printf("  ok  duplicate_ids_rejected\n");
}

int main(void) {
    printf("running cpm tests:\n");
    test_textbook_network();
    test_single_activity();
    test_parallel_paths();
    test_cycle_rejected();
    test_duplicate_ids_rejected();
    printf("all tests passed.\n");
    return 0;
}
