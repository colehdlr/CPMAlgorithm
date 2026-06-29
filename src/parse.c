#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

static char *read_file(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "parse: cannot open '%s'\n", path); return NULL; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);
    char *buf = malloc((size_t)size + 1);
    if (buf) {
        fread(buf, 1, (size_t)size, f);
        buf[size] = '\0';
    }
    fclose(f);
    return buf;
}

static int find_id(const Activity *activities, int count, char id) {
    for (int i = 0; i < count; ++i) {
        if (activities[i].id == id) return i;
    }
    return -1;
}

bool parse_load_from_json(const char *path,
                          Activity **out_activities, int *out_count) {
    char *text = read_file(path);
    if (!text) return false;

    cJSON *root = cJSON_Parse(text);
    free(text);
    if (!root) {
        fprintf(stderr, "parse: JSON parse error\n");
        return false;
    }

    Activity *activities = NULL;
    int count = 0;
    bool ok = false;

    cJSON *array = cJSON_GetObjectItemCaseSensitive(root, "activities");
    if (!cJSON_IsArray(array) || cJSON_GetArraySize(array) <= 0) {
        fprintf(stderr, "parse: missing or empty 'activities' array\n");
        goto done;
    }

    count = cJSON_GetArraySize(array);
    activities = calloc((size_t)count, sizeof(Activity));
    if (!activities) goto done;

    /* First pass: copy fields, validate id/duration/uniqueness. */
    for (int i = 0; i < count; ++i) {
        cJSON *item     = cJSON_GetArrayItem(array, i);
        cJSON *id_node  = cJSON_GetObjectItemCaseSensitive(item, "id");
        cJSON *name     = cJSON_GetObjectItemCaseSensitive(item, "name");
        cJSON *duration = cJSON_GetObjectItemCaseSensitive(item, "duration");

        if (!cJSON_IsString(id_node) || !id_node->valuestring
            || strlen(id_node->valuestring) != 1) {
            fprintf(stderr, "parse: activity[%d] 'id' must be a single character\n", i);
            goto done;
        }
        if (!cJSON_IsNumber(duration) || duration->valuedouble < 0) {
            fprintf(stderr, "parse: activity '%c' missing non-negative numeric 'duration'\n",
                    id_node->valuestring[0]);
            goto done;
        }
        char id = id_node->valuestring[0];
        if (find_id(activities, i, id) >= 0) {
            fprintf(stderr, "parse: duplicate activity id '%c'\n", id);
            goto done;
        }

        Activity *a = &activities[i];
        a->id = id;
        snprintf(a->name, sizeof(a->name), "%s",
                 cJSON_IsString(name) ? name->valuestring : id_node->valuestring);
        a->duration = (int)duration->valuedouble;
    }

    /* Second pass: resolve dependency ids to indices. */
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(array, i);
        cJSON *deps_node = cJSON_GetObjectItemCaseSensitive(item, "dependencies");
        if (!deps_node) continue;
        if (!cJSON_IsArray(deps_node)) {
            fprintf(stderr, "parse: activity '%c' 'dependencies' must be an array\n",
                    activities[i].id);
            goto done;
        }
        int n = cJSON_GetArraySize(deps_node);
        if (n > MAX_DEPS) {
            fprintf(stderr, "parse: activity '%c' has too many deps (max %d)\n",
                    activities[i].id, MAX_DEPS);
            goto done;
        }
        for (int k = 0; k < n; ++k) {
            cJSON *dep_node = cJSON_GetArrayItem(deps_node, k);
            if (!cJSON_IsString(dep_node) || !dep_node->valuestring
                || strlen(dep_node->valuestring) != 1) {
                fprintf(stderr, "parse: activity '%c' has non-single-char dependency\n",
                        activities[i].id);
                goto done;
            }
            int dep = find_id(activities, count, dep_node->valuestring[0]);
            if (dep < 0 || dep == i) {
                fprintf(stderr, "parse: activity '%c' has bad dependency '%c'\n",
                        activities[i].id, dep_node->valuestring[0]);
                goto done;
            }
            activities[i].deps[activities[i].dep_count++] = dep;
        }
    }

    ok = true;

done:
    cJSON_Delete(root);
    if (!ok) {
        free(activities);
        return false;
    }
    *out_activities = activities;
    *out_count = count;
    return true;
}

bool topological_sort(const Activity *activities, int count, int **out_order) {
    if (count <= 0) return false;

    int *in_degree = malloc((size_t)count * sizeof(int));
    int *order     = malloc((size_t)count * sizeof(int));
    if (!in_degree || !order) { free(in_degree); free(order); return false; }

    for (int i = 0; i < count; ++i) in_degree[i] = activities[i].dep_count;

    /* Kahn's algorithm. Successors are found by scanning the array. */
    int produced = 0;
    while (produced < count) {
        int picked = -1;
        for (int i = 0; i < count; ++i) {
            if (in_degree[i] == 0) { picked = i; break; }
        }
        if (picked < 0) {
            fprintf(stderr, "parse: cycle detected\n");
            free(in_degree); free(order);
            return false;
        }
        in_degree[picked] = -1;
        order[produced++] = picked;
        for (int j = 0; j < count; ++j) {
            for (int k = 0; k < activities[j].dep_count; ++k) {
                if (activities[j].deps[k] == picked) { in_degree[j]--; break; }
            }
        }
    }

    free(in_degree);
    *out_order = order;
    return true;
}
