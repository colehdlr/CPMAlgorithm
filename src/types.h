#ifndef TYPES_H
#define TYPES_H

#define MAX_DEPS     32
#define MAX_NAME_LEN 64

typedef struct {
    char id;                  /* single-char identifier ('A', 'B', ...) */
    char name[MAX_NAME_LEN];
    int  duration;
    int  dep_count;
    int  deps[MAX_DEPS];      /* indices into the activities array */
} Activity;

#endif /* TYPES_H */
