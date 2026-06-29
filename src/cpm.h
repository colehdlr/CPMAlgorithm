#ifndef CPM_H
#define CPM_H

typedef struct {
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
    int free_float;
    int total_float;
} CPMResult;

#endif /* CPM_H */
