#ifndef CPM_H
#define CPM_H

#define MAX_DEPS     16
#define MAX_NAME_LEN 64

typedef struct {
    char id;                  /* single-char identifier ('A', 'B', ...) */
    char name[MAX_NAME_LEN];
    int  duration;
    int  dep_count;
    int  deps[MAX_DEPS];      /* indices into the activities array */
} Activity;

typedef struct {
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
    int total_float;
    int free_float;
} CPMResult;

/* Topologically sort the graph, then run forward + backward CPM passes.
 * Returns a malloc'd array of `count` CPMResult (caller frees) on success,
 * NULL on cycle or out of memory (prints a message to stderr in both cases). */
CPMResult *cpm_compute(const Activity *activities, int count);

#endif /* CPM_H */
