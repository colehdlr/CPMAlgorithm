#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>

#define MAX_DEPS 16

typedef struct {
    char id;
    char name[64];
    int  duration;
    int  dep_count;
    char deps_on_ids[MAX_DEPS];
} Activity;

int  find_activity(const Activity *items, int count, char id);
bool load_activities(const char *path, Activity **out, int *count);

#endif
