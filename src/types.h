#ifndef TYPES_H
#define TYPES_H

#define MAX_DEPS 16

typedef struct {
    char id;
    char name[64];
    int duratioon;
    int dep_count;
    char deps_on_ids[MAX_DEPS];
} Activity;

#endif // TYPES_H
