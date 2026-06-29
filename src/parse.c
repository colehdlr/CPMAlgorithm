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

int find_activity(const Activity *items, int count, char id) {
    for (int i = 0; i < count; ++i) {
        if (items[i].id == id) return i;
    }
    return -1;
}

bool load_activities(const char *path, Activity **out, int *out_count) {
    *out = NULL;
    *out_count = 0;

    char *text = read_file(path);
    if (!text) return false;

    cJSON *root = cJSON_Parse(text);
    free(text);
    if (!root) {
        fprintf(stderr, "parse: JSON parse error\n");
        return false;
    }

    bool ok = false;
    cJSON *activities = cJSON_GetObjectItemCaseSensitive(root, "activities");
    if (!cJSON_IsArray(activities) || cJSON_GetArraySize(activities) <= 0) {
        fprintf(stderr, "parse: missing or empty 'activities' array\n");
        goto done;
    }

    int count = cJSON_GetArraySize(activities);
    Activity *items = calloc((size_t)count, sizeof(Activity));
    if (!items) goto done;

    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(activities, i);
        cJSON *id_node       = cJSON_GetObjectItemCaseSensitive(item, "id");
        cJSON *name_node     = cJSON_GetObjectItemCaseSensitive(item, "name");
        cJSON *duration_node = cJSON_GetObjectItemCaseSensitive(item, "duration");

        if (!cJSON_IsString(id_node) || !id_node->valuestring || !id_node->valuestring[0]) {
            fprintf(stderr, "parse: activity[%d] missing non-empty string 'id'\n", i);
            goto fail;
        }
        if (!cJSON_IsNumber(duration_node) || duration_node->valuedouble < 0) {
            fprintf(stderr, "parse: activity '%s' missing non-negative numeric 'duration'\n",
                    id_node->valuestring);
            goto fail;
        }

        char id_char = id_node->valuestring[0];
        for (int j = 0; j < i; ++j) {
            if (items[j].id == id_char) {
                fprintf(stderr, "parse: duplicate activity id '%c'\n", id_char);
                goto fail;
            }
        }

        Activity *a = &items[i];
        a->id = id_char;
        snprintf(a->name, sizeof(a->name), "%s",
                 cJSON_IsString(name_node) ? name_node->valuestring : id_node->valuestring);
        a->duration = (int)duration_node->valuedouble;
    }

    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(activities, i);
        cJSON *deps_node = cJSON_GetObjectItemCaseSensitive(item, "dependencies");
        if (!deps_node) continue;
        if (!cJSON_IsArray(deps_node)) {
            fprintf(stderr, "parse: activity '%c' 'dependencies' must be an array\n",
                    items[i].id);
            goto fail;
        }
        int num_deps = cJSON_GetArraySize(deps_node);
        if (num_deps > MAX_DEPS) {
            fprintf(stderr, "parse: activity '%c' has too many deps (max %d)\n",
                    items[i].id, MAX_DEPS);
            goto fail;
        }
        for (int k = 0; k < num_deps; ++k) {
            cJSON *dep_node = cJSON_GetArrayItem(deps_node, k);
            if (!cJSON_IsString(dep_node) || !dep_node->valuestring[0]) goto fail;
            char dep_id = dep_node->valuestring[0];
            int dep_idx = find_activity(items, count, dep_id);
            if (dep_idx < 0 || dep_idx == i) {
                fprintf(stderr, "parse: activity '%c' has bad dependency '%c'\n",
                        items[i].id, dep_id);
                goto fail;
            }
            items[i].deps_on_ids[items[i].dep_count++] = dep_id;
        }
    }

    *out = items;
    *out_count = count;
    ok = true;
    goto done;

fail:
    free(items);
done:
    cJSON_Delete(root);
    return ok;
}
