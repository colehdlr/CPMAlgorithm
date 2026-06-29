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

void graph_init(Graph *graph) {
    graph->items = NULL;
    graph->count = 0;
    graph->topo_order = NULL;
    graph->project_duration = 0;
}

void graph_free(Graph *graph) {
    if (!graph) return;
    free(graph->items);
    free(graph->topo_order);
    graph_init(graph);
}

int graph_find_id(const Graph *graph, const char *id) {
    for (int i = 0; i < graph->count; ++i) {
        if (strcmp(graph->items[i].id, id) == 0) return i;
    }
    return -1;
}

bool graph_load_from_json(const char *path, Graph *graph) {
    graph_init(graph);

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
    graph->items = calloc((size_t)count, sizeof(Activity));
    if (!graph->items) goto done;

    /* First pass: copy fields, validate id/duration/uniqueness. */
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(activities, i);
        cJSON *id_node       = cJSON_GetObjectItemCaseSensitive(item, "id");
        cJSON *name_node     = cJSON_GetObjectItemCaseSensitive(item, "name");
        cJSON *duration_node = cJSON_GetObjectItemCaseSensitive(item, "duration");

        if (!cJSON_IsString(id_node) || !id_node->valuestring || !id_node->valuestring[0]) {
            fprintf(stderr, "parse: activity[%d] missing non-empty string 'id'\n", i);
            goto done;
        }
        if (!cJSON_IsNumber(duration_node) || duration_node->valuedouble < 0) {
            fprintf(stderr, "parse: activity '%s' missing non-negative numeric 'duration'\n",
                    id_node->valuestring);
            goto done;
        }
        for (int j = 0; j < i; ++j) {
            if (strcmp(graph->items[j].id, id_node->valuestring) == 0) {
                fprintf(stderr, "parse: duplicate activity id '%s'\n", id_node->valuestring);
                goto done;
            }
        }

        Activity *a = &graph->items[i];
        snprintf(a->id, sizeof(a->id), "%s", id_node->valuestring);
        snprintf(a->name, sizeof(a->name), "%s",
                 cJSON_IsString(name_node) ? name_node->valuestring : a->id);
        a->duration = (int)duration_node->valuedouble;
    }
    graph->count = count;

    /* Second pass: resolve dependency ids to indices. */
    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(activities, i);
        cJSON *deps_node = cJSON_GetObjectItemCaseSensitive(item, "dependencies");
        if (!deps_node) continue;
        if (!cJSON_IsArray(deps_node)) {
            fprintf(stderr, "parse: activity '%s' 'dependencies' must be an array\n",
                    graph->items[i].id);
            goto done;
        }
        int num_deps = cJSON_GetArraySize(deps_node);
        if (num_deps > CPM_MAX_DEPS) {
            fprintf(stderr, "parse: activity '%s' has too many deps (max %d)\n",
                    graph->items[i].id, CPM_MAX_DEPS);
            goto done;
        }
        for (int k = 0; k < num_deps; ++k) {
            cJSON *dep_node = cJSON_GetArrayItem(deps_node, k);
            if (!cJSON_IsString(dep_node)) goto done;
            int dep = graph_find_id(graph, dep_node->valuestring);
            if (dep < 0 || dep == i) {
                fprintf(stderr, "parse: activity '%s' has bad dependency '%s'\n",
                        graph->items[i].id, dep_node->valuestring);
                goto done;
            }
            graph->items[i].deps[graph->items[i].num_deps++] = dep;
        }
    }

    ok = true;

done:
    cJSON_Delete(root);
    if (!ok) graph_free(graph);
    return ok;
}

bool graph_topological_sort(Graph *graph) {
    int count = graph->count;
    if (count <= 0) return false;

    int *in_degree = malloc((size_t)count * sizeof(int));
    int *order     = malloc((size_t)count * sizeof(int));
    if (!in_degree || !order) { free(in_degree); free(order); return false; }

    for (int i = 0; i < count; ++i) in_degree[i] = graph->items[i].num_deps;

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
            for (int k = 0; k < graph->items[j].num_deps; ++k) {
                if (graph->items[j].deps[k] == picked) { in_degree[j]--; break; }
            }
        }
    }

    free(graph->topo_order);
    graph->topo_order = order;
    free(in_degree);
    return true;
}
