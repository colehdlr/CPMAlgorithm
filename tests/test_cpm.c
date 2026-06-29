#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "parse.h"
#include "cpm.h"

/*
 * Minimal self-contained test driver for parse + cpm.
 *
 * Builds a small activity array in memory (no JSON), runs topological sort
 * and CPM, and asserts the expected ES/EF/LS/LF/slack/critical values.
 *
 * Run with `make test`.
 */

#define MAX_TEST_ACTIVITIES 32

typedef struct {
    Activity items[MAX_TEST_ACTIVITIES];
    int count;
} ActivityList;

static int add_activity(ActivityList *list, char id, const char *name, int duration,
                        const int *deps, int dep_count) {
    assert(list->count < MAX_TEST_ACTIVITIES);
    Activity *a = &list->items[list->count];
    memset(a, 0, sizeof(*a));
    a->id = id;
    snprintf(a->name, sizeof(a->name), "%s", name);
    a->duration = duration;
    a->dep_count = dep_count;
    for (int i = 0; i < dep_count; ++i) a->deps[i] = deps[i];
    return list->count++;
}

static int find_idx(const ActivityList *list, char id) {
    for (int i = 0; i < list->count; ++i) {
        if (list->items[i].id == id) return i;
    }
    return -1;
}

static void test_textbook_network(void) {
    /* Same shape as data/activities.json so the test mirrors the demo. */
    ActivityList list = {0};
    int A = add_activity(&list, 'A', "Requirements",   3, NULL, 0);
    (void)A;
    int B = add_activity(&list, 'B', "Design",         4, (int[]){0}, 1);
    int C = add_activity(&list, 'C', "Database",       5, (int[]){0}, 1);
    int D = add_activity(&list, 'D', "Frontend",       6, (int[]){B}, 1);
    int E = add_activity(&list, 'E', "Backend",        7, (int[]){C}, 1);
    int F = add_activity(&list, 'F', "Integration",    3, (int[]){D, E}, 2);
    int G = add_activity(&list, 'G', "Testing",        4, (int[]){F}, 1);
    (void)G;

    int *topo = NULL;
    assert(topological_sort(list.items, list.count, &topo));

    CPMResult *results = calloc((size_t)list.count, sizeof(CPMResult));
    int project_duration = 0;
    assert(cpm_compute(list.items, list.count, topo, results, &project_duration));

    assert(project_duration == 22);

    /* Spot-check each activity */
    struct { char id; int es, ef, ls, lf, slack; int crit; } expected[] = {
        { 'A', 0,  3,  0,  3, 0, 1 },
        { 'B', 3,  7,  5,  9, 2, 0 },
        { 'C', 3,  8,  3,  8, 0, 1 },
        { 'D', 7, 13,  9, 15, 2, 0 },
        { 'E', 8, 15,  8, 15, 0, 1 },
        { 'F',15, 18, 15, 18, 0, 1 },
        { 'G',18, 22, 18, 22, 0, 1 },
    };
    for (size_t i = 0; i < sizeof(expected)/sizeof(expected[0]); ++i) {
        int idx = find_idx(&list, expected[i].id);
        assert(idx >= 0);
        const CPMResult *r = &results[idx];
        bool crit = (r->total_float == 0);
        if (r->earliest_start != expected[i].es || r->earliest_finish != expected[i].ef
            || r->latest_start != expected[i].ls || r->latest_finish != expected[i].lf
            || r->total_float != expected[i].slack
            || crit != (bool)expected[i].crit) {
            fprintf(stderr,
                "mismatch on %c: got ES=%d EF=%d LS=%d LF=%d slack=%d crit=%d\n"
                "           want ES=%d EF=%d LS=%d LF=%d slack=%d crit=%d\n",
                expected[i].id,
                r->earliest_start, r->earliest_finish,
                r->latest_start, r->latest_finish,
                r->total_float, (int)crit,
                expected[i].es, expected[i].ef, expected[i].ls, expected[i].lf,
                expected[i].slack, expected[i].crit);
            abort();
        }
    }

    free(topo);
    free(results);
    printf("  ok  textbook_network\n");
}

static void test_single_activity(void) {
    ActivityList list = {0};
    add_activity(&list, 'X', "Only", 5, NULL, 0);

    int *topo = NULL;
    assert(topological_sort(list.items, list.count, &topo));

    CPMResult *results = calloc((size_t)list.count, sizeof(CPMResult));
    int project_duration = 0;
    assert(cpm_compute(list.items, list.count, topo, results, &project_duration));

    assert(project_duration == 5);
    assert(results[0].earliest_start == 0 && results[0].earliest_finish == 5);
    assert(results[0].latest_start   == 0 && results[0].latest_finish   == 5);
    assert(results[0].total_float == 0);

    free(topo);
    free(results);
    printf("  ok  single_activity\n");
}

static void test_parallel_paths(void) {
    /* Two parallel chains from S to T:
     *     S(2) -> A(5) -> T(1)        path = 8 (critical)
     *     S(2) -> B(3) -> T(1)        path = 6
     *
     * A is critical, B is not (slack 2).
     */
    ActivityList list = {0};
    int S = add_activity(&list, 'S', "Start", 2, NULL, 0);
    int A = add_activity(&list, 'A', "A",     5, (int[]){S}, 1);
    int B = add_activity(&list, 'B', "B",     3, (int[]){S}, 1);
    int T = add_activity(&list, 'T', "End",   1, (int[]){A, B}, 2);
    (void)T;

    int *topo = NULL;
    assert(topological_sort(list.items, list.count, &topo));

    CPMResult *results = calloc((size_t)list.count, sizeof(CPMResult));
    int project_duration = 0;
    assert(cpm_compute(list.items, list.count, topo, results, &project_duration));

    assert(project_duration == 8);
    assert(results[find_idx(&list, 'A')].total_float == 0);
    assert(results[find_idx(&list, 'B')].total_float == 2);

    free(topo);
    free(results);
    printf("  ok  parallel_paths\n");
}

static void test_cycle_rejected(void) {
    /* A -> B -> A is a cycle; topological sort must fail. */
    ActivityList list = {0};
    int A = add_activity(&list, 'A', "A", 1, (int[]){1}, 1);   /* will reference B */
    int B = add_activity(&list, 'B', "B", 1, (int[]){A}, 1);
    (void)B;

    int *topo = NULL;
    assert(!topological_sort(list.items, list.count, &topo));

    printf("  ok  cycle_rejected\n");
}

int main(void) {
    printf("running cpm tests:\n");
    test_textbook_network();
    test_single_activity();
    test_parallel_paths();
    test_cycle_rejected();
    printf("all tests passed.\n");
    return 0;
}
