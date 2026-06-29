#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>

#include "types.h"

/* Load and validate activities from a JSON file.
 *
 * On success, *out_activities is a malloc'd array of *out_count Activity
 * structs (caller frees), with dependency IDs already resolved to indices.
 *
 * Validates: non-empty single-char unique ids, non-negative durations,
 * resolvable non-self dependencies. On failure, prints an error to stderr
 * and leaves the out-params untouched (caller should zero-init). */
bool parse_load_from_json(const char *path,
                          Activity **out_activities, int *out_count);

/* Kahn's algorithm. On success, *out_order is a malloc'd array of `count`
 * indices in topological order (caller frees). Returns false on cycle. */
bool topological_sort(const Activity *activities, int count, int **out_order);

#endif /* PARSE_H */
