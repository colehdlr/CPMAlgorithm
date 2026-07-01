#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpm.h"
#include "render.h"

static int find_id(const Activity *a, int count, char id) {
    for (int i = 0; i < count; ++i) if (a[i].id == id) return i;
    return -1;
}

/* Load activities from a whitespace-separated text file. Each non-blank line:
 *     ID NAME OPTIMISTIC MOST_LIKELY PESSIMISTIC [DEP_ID ...]
 * The three-point PERT estimate is mandatory; cpm_compute() schedules the
 * activity using round((O + 4M + P) / 6) as its duration.
 * Returns a malloc'd array (caller frees), writes count to *out_count.
 * Returns NULL and prints a message to stderr on error. */
static Activity *parse_load(const char *path, int *out_count) {
    FILE *f = fopen(path, "r");
    if (!f) { fprintf(stderr, "parse: cannot open '%s'\n", path); return NULL; }

    Activity *activities = NULL;
    char line[512];
    int count = 0, line_num = 0;

    /* Pass 1: count non-blank lines. */
    while (fgets(line, sizeof(line), f)) {
        char *t = line;
        while (*t == ' ' || *t == '\t') t++;
        if (*t != '\n' && *t != '\r' && *t != '\0') count++;
    }
    if (count == 0) {
        fprintf(stderr, "parse: no activities in '%s'\n", path);
        goto fail;
    }
    rewind(f);

    activities = calloc((size_t)count, sizeof(Activity));
    if (!activities) goto fail;

    /* Pass 2: tokenize each line. */
    int i = 0;
    while (fgets(line, sizeof(line), f) && i < count) {
        line_num++;
        char *id_tok = strtok(line, " \t\r\n");
        if (!id_tok) continue;
        char *name_tok = strtok(NULL, " \t\r\n");
        char *o_tok = strtok(NULL, " \t\r\n");
        char *m_tok = strtok(NULL, " \t\r\n");
        char *p_tok = strtok(NULL, " \t\r\n");
        if (strlen(id_tok) != 1 || !name_tok || !o_tok || !m_tok || !p_tok
            || find_id(activities, i, id_tok[0]) >= 0) goto parse_err;
        activities[i].id = id_tok[0];
        snprintf(activities[i].name, sizeof(activities[i].name), "%s", name_tok);

        char *o_end, *m_end, *p_end;
        long o = strtol(o_tok, &o_end, 10);
        long m = strtol(m_tok, &m_end, 10);
        long p = strtol(p_tok, &p_end, 10);
        if (*o_end != '\0' || *m_end != '\0' || *p_end != '\0'
            || o < 0 || o > m || m > p) goto parse_err;
        activities[i].optimistic  = (int)o;
        activities[i].most_likely = (int)m;
        activities[i].pessimistic = (int)p;

        char *tok = strtok(NULL, " \t\r\n");
        /* Remaining tokens are dep ids, stored raw and resolved to indices after pass 2. */
        while (tok != NULL) {
            if (strlen(tok) != 1 || activities[i].dep_count >= MAX_DEPS) goto parse_err;
            activities[i].deps[activities[i].dep_count++] = (unsigned char)tok[0];
            tok = strtok(NULL, " \t\r\n");
        }
        i++;
    }
    fclose(f);

    for (int j = 0; j < count; ++j) {
        for (int k = 0; k < activities[j].dep_count; ++k) {
            int dep = find_id(activities, count, (char)activities[j].deps[k]);
            if (dep < 0 || dep == j) {
                fprintf(stderr, "parse: bad dependency on activity '%c'\n", activities[j].id);
                free(activities);
                return NULL;
            }
            activities[j].deps[k] = dep;
        }
    }

    *out_count = count;
    return activities;

parse_err:
    fprintf(stderr, "parse: error at line %d in '%s'\n", line_num, path);
fail:
    free(activities);
    fclose(f);
    return NULL;
}

int main(int argc, char **argv) {
    const char *path = (argc > 1) ? argv[1] : "data/activities.txt";

    int count = 0;
    Activity *activities = parse_load(path, &count);
    if (!activities) return 1;

    CPMResult *results = cpm_compute(activities, count);
    if (!results) { free(activities); return 1; }

    PERTSummary pert = pert_compute(activities, results, count);
    pert_print_table(activities, results, count, pert);

    render_run(activities, count, results, pert);

    free(results);
    free(activities);
    return 0;
}
