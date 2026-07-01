#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "cpm.h"

#define COUNT(a) ((int)(sizeof(a) / sizeof((a)[0])))

static int max_ef(const CPMResult *r, int count) {
    int m = 0;
    for (int i = 0; i < count; ++i) {
        if (r[i].earliest_finish > m) m = r[i].earliest_finish;
    }
    return m;
}

static void test_textbook(void) {
    Activity activities[] = {
        { .id='A', .name="Requirements", .duration=3 },
        { .id='B', .name="Design",       .duration=4, .dep_count=1, .deps={0} },
        { .id='C', .name="Database",     .duration=5, .dep_count=1, .deps={0} },
        { .id='D', .name="Frontend",     .duration=6, .dep_count=1, .deps={1} },
        { .id='E', .name="Backend",      .duration=7, .dep_count=1, .deps={2} },
        { .id='F', .name="Integration",  .duration=3, .dep_count=2, .deps={3,4} },
        { .id='G', .name="Testing",      .duration=4, .dep_count=1, .deps={5} },
    };
    int count = COUNT(activities);

    CPMResult *r = cpm_compute(activities, count);
    assert(r);
    assert(max_ef(r, count) == 22);

    struct { int es, ef, ls, lf, tf, ff; } want[] = {
        { 0,  3,  0,  3, 0, 0 },
        { 3,  7,  5,  9, 2, 0 },
        { 3,  8,  3,  8, 0, 0 },
        { 7, 13,  9, 15, 2, 2 },
        { 8, 15,  8, 15, 0, 0 },
        {15, 18, 15, 18, 0, 0 },
        {18, 22, 18, 22, 0, 0 },
    };
    for (int i = 0; i < count; ++i) {
        assert(r[i].earliest_start  == want[i].es);
        assert(r[i].earliest_finish == want[i].ef);
        assert(r[i].latest_start    == want[i].ls);
        assert(r[i].latest_finish   == want[i].lf);
        assert(r[i].total_float     == want[i].tf);
        assert(r[i].free_float      == want[i].ff);
    }

    free(r);
    printf("  ok  textbook\n");
}

static void test_single(void) {
    Activity activities[] = { { .id='X', .name="Only", .duration=5 } };
    CPMResult *r = cpm_compute(activities, 1);
    assert(r);
    assert(r[0].earliest_start == 0 && r[0].earliest_finish == 5);
    assert(r[0].latest_start   == 0 && r[0].latest_finish   == 5);
    assert(r[0].total_float == 0);
    assert(r[0].free_float  == 0);
    free(r);
    printf("  ok  single\n");
}

static void test_parallel(void) {
    /* Two parallel chains: S->A->T = 8 (critical), S->B->T = 6. */
    Activity activities[] = {
        { .id='S', .name="Start", .duration=2 },
        { .id='A', .name="A",     .duration=5, .dep_count=1, .deps={0} },
        { .id='B', .name="B",     .duration=3, .dep_count=1, .deps={0} },
        { .id='T', .name="End",   .duration=1, .dep_count=2, .deps={1,2} },
    };
    int count = COUNT(activities);

    CPMResult *r = cpm_compute(activities, count);
    assert(r);
    assert(max_ef(r, count) == 8);
    assert(r[1].total_float == 0);  /* A on critical path */
    assert(r[2].total_float == 2);
    assert(r[2].free_float  == 2);

    free(r);
    printf("  ok  parallel\n");
}

static void test_cycle(void) {
    /* A -> B -> A. cpm_compute must reject it. */
    Activity activities[] = {
        { .id='A', .name="A", .duration=1, .dep_count=1, .deps={1} },
        { .id='B', .name="B", .duration=1, .dep_count=1, .deps={0} },
    };
    assert(cpm_compute(activities, COUNT(activities)) == NULL);
    printf("  ok  cycle\n");
}

static void assert_close(double a, double b) {
    assert(fabs(a - b) < 1e-9);
}

static void test_pert(void) {
    /* Same parallel-chain shape as test_parallel: S->A->T = 8 (critical),
     * S->B->T = 6 (2 slack). A has O=2 M=4 P=12: expected = (2+16+12)/6 = 5,
     * variance = ((12-2)/6)^2 = 100/36. S, B, T have O=M=P=duration, which
     * collapses their expected to `duration` and variance to 0. Project
     * PERT duration/variance must sum only the critical (S, A, T) activities. */
    Activity activities[] = {
        { .id='S', .name="Start", .duration=2, .optimistic=2, .most_likely=2, .pessimistic=2 },
        { .id='A', .name="A",     .duration=5, .dep_count=1, .deps={0},
          .optimistic=2, .most_likely=4, .pessimistic=12 },
        { .id='B', .name="B",     .duration=3, .dep_count=1, .deps={0},
          .optimistic=3, .most_likely=3, .pessimistic=3 },
        { .id='T', .name="End",   .duration=1, .dep_count=2, .deps={1,2},
          .optimistic=1, .most_likely=1, .pessimistic=1 },
    };
    int count = COUNT(activities);

    CPMResult *r = cpm_compute(activities, count);
    assert(r);
    assert(r[1].total_float == 0);  /* A on critical path */
    assert(r[2].total_float == 2);  /* B has 2 slack, excluded from project PERT sum */

    PERTSummary pert = pert_compute(activities, r, count);
    assert_close(r[1].pert_expected, 5.0);
    assert_close(r[1].pert_variance, 100.0 / 36.0);
    assert_close(r[2].pert_expected, 3.0);
    assert_close(r[2].pert_variance, 0.0);
    assert_close(pert.project_pert_duration, 8.0);  /* S(2) + A(5) + T(1) */
    assert_close(pert.project_variance, 100.0 / 36.0);

    free(r);
    printf("  ok  pert\n");
}

int main(void) {
    printf("running cpm tests:\n");
    test_textbook();
    test_single();
    test_parallel();
    test_cycle();
    test_pert();
    printf("all tests passed.\n");
    return 0;
}
