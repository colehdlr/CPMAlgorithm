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

    /* Three-point (PERT) estimates. Default to `duration` for all three
     * when the input doesn't supply them, which collapses pert_expected
     * to `duration` and pert_variance to 0. */
    int  optimistic, most_likely, pessimistic;
} Activity;

typedef struct {
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
    int total_float;
    int free_float;

    double pert_expected;   /* (O + 4M + P) / 6 */
    double pert_variance;   /* ((P - O) / 6)^2 */
    double pert_stddev;
} CPMResult;

typedef struct {
    double project_pert_duration;
    double project_variance;
    double project_stddev;
} PERTSummary;

/* Topologically sort the graph, then run forward + backward CPM passes.
 * Returns a malloc'd array of `count` CPMResult (caller frees) on success,
 * NULL on cycle or out of memory (prints a message to stderr in both cases). */
CPMResult *cpm_compute(const Activity *activities, int count);

/* PERT three-point estimation. For every activity, computes:
 *   pert_expected = (optimistic + 4*most_likely + pessimistic) / 6
 *   pert_variance = ((pessimistic - optimistic) / 6)^2
 * Then sums expected time and variance over the critical path (total_float
 * == 0, as found by cpm_compute) into the returned summary.
 * Requires cpm_compute() to have run first so total_float is populated. */
PERTSummary pert_compute(const Activity *activities, CPMResult *results, int count);

/* Print per-activity O/M/P/expected/stddev plus the project-level PERT
 * expected duration and a 95% confidence interval (+/- 1.96 stddev). */
void pert_print_table(const Activity *activities, const CPMResult *results,
                       int count, PERTSummary summary);

#endif /* CPM_H */
