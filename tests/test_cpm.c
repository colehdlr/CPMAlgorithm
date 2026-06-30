#include <assert.h>
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

    struct { int es, ef, ls, lf, slack; } want[] = {
        { 0,  3,  0,  3, 0 },
        { 3,  7,  5,  9, 2 },
        { 3,  8,  3,  8, 0 },
        { 7, 13,  9, 15, 2 },
        { 8, 15,  8, 15, 0 },
        {15, 18, 15, 18, 0 },
        {18, 22, 18, 22, 0 },
    };
    for (int i = 0; i < count; ++i) {
        assert(r[i].earliest_start  == want[i].es);
        assert(r[i].earliest_finish == want[i].ef);
        assert(r[i].latest_start    == want[i].ls);
        assert(r[i].latest_finish   == want[i].lf);
        assert(r[i].total_float     == want[i].slack);
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
    free(r);
    printf("  ok  single\n");
}

static void test_parallel(void) {
    /* Two parallel chains: S->A->T = 8 (critical), S->B->T = 6 (B has slack 2). */
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
    assert(r[2].total_float == 2);  /* B has slack */

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

int main(void) {
    printf("running cpm tests:\n");
    test_textbook();
    test_single();
    test_parallel();
    test_cycle();
    printf("all tests passed.\n");
    return 0;
}
