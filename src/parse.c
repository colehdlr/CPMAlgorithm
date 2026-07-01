#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

static char *read_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) { fprintf(stderr, "parse: cannot open '%s'\n", path); return NULL; }

    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return NULL; }
    long size = ftell(file);
    if (size < 0) { fclose(file); return NULL; }
    rewind(file);

    char *buffer = malloc((size_t)size + 1);
    if (!buffer) { fclose(file); return NULL; }
    size_t read = fread(buffer, 1, (size_t)size, file);
    fclose(file);
    if ((long)read != size) { free(buffer); return NULL; }
    buffer[size] = '\0';
    return buffer;
}

static void copy_string_field(char *dst, size_t dst_size, const char *src) {
    if (!src) { dst[0] = '\0'; return; }
    size_t len = strlen(src);
    if (len >= dst_size) len = dst_size - 1;
    memcpy(dst, src, len);
    dst[len] = '\0';
}

static bool ensure_capacity(Graph *graph, int needed) {
    if (graph->capacity >= needed) return true;
    int new_capacity = graph->capacity ? graph->capacity * 2 : 8;
    while (new_capacity < needed) new_capacity *= 2;
    Activity *grown = realloc(graph->items, (size_t)new_capacity * sizeof(Activity));
    if (!grown) return false;
    graph->items = grown;
    graph->capacity = new_capacity;
    return true;
}

void graph_init(Graph *graph) {
    graph->items = NULL;
    graph->count = 0;
    graph->capacity = 0;
    graph->topo_order = NULL;
    graph->project_duration = 0;
    graph->project_pert_duration = 0.0;
    graph->project_variance = 0.0;
    graph->project_stddev = 0.0;
}

void graph_free(Graph *graph) {
    if (!graph) return;
    free(graph->items);
    free(graph->topo_order);
    graph_init(graph);
}

int graph_find_id(const Graph *graph, const char *id) {
    if (!graph || !id) return -1;
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
        const char *err = cJSON_GetErrorPtr();
        fprintf(stderr, "parse: JSON parse error near: %s\n", err ? err : "(unknown)");
        return false;
    }

    const cJSON **pending_deps = NULL;
    bool ok = false;

    cJSON *activities = cJSON_GetObjectItemCaseSensitive(root, "activities");
    if (!cJSON_IsArray(activities)) {
        fprintf(stderr, "parse: missing top-level 'activities' array\n");
        goto done;
    }

    int count = cJSON_GetArraySize(activities);
    if (!ensure_capacity(graph, count)) {
        fprintf(stderr, "parse: out of memory (need %d activities)\n", count);
        goto done;
    }

    pending_deps = calloc((size_t)count, sizeof(*pending_deps));
    if (!pending_deps) goto done;

    for (int i = 0; i < count; ++i) {
        cJSON *item = cJSON_GetArrayItem(activities, i);
        if (!cJSON_IsObject(item)) {
            fprintf(stderr, "parse: activity[%d] is not an object\n", i);
            goto done;
        }

        cJSON *id_node          = cJSON_GetObjectItemCaseSensitive(item, "id");
        cJSON *name_node        = cJSON_GetObjectItemCaseSensitive(item, "name");
        cJSON *duration_node    = cJSON_GetObjectItemCaseSensitive(item, "duration");
        cJSON *deps_node        = cJSON_GetObjectItemCaseSensitive(item, "dependencies");
        cJSON *optimistic_node  = cJSON_GetObjectItemCaseSensitive(item, "optimistic");
        cJSON *most_likely_node = cJSON_GetObjectItemCaseSensitive(item, "most_likely");
        cJSON *pessimistic_node = cJSON_GetObjectItemCaseSensitive(item, "pessimistic");

        if (!cJSON_IsString(id_node) || !id_node->valuestring) {
            fprintf(stderr, "parse: activity[%d] missing string 'id'\n", i);
            goto done;
        }
        if (!cJSON_IsNumber(duration_node)) {
            fprintf(stderr, "parse: activity '%s' missing numeric 'duration'\n", id_node->valuestring);
            goto done;
        }
        if (deps_node && !cJSON_IsArray(deps_node)) {
            fprintf(stderr, "parse: activity '%s' 'dependencies' must be an array\n", id_node->valuestring);
            goto done;
        }
        if ((optimistic_node && !cJSON_IsNumber(optimistic_node))
            || (most_likely_node && !cJSON_IsNumber(most_likely_node))
            || (pessimistic_node && !cJSON_IsNumber(pessimistic_node))) {
            fprintf(stderr, "parse: activity '%s' has a non-numeric PERT estimate\n", id_node->valuestring);
            goto done;
        }

        Activity *activity = &graph->items[i];
        memset(activity, 0, sizeof(*activity));
        copy_string_field(activity->id, sizeof(activity->id), id_node->valuestring);
        copy_string_field(activity->name, sizeof(activity->name),
                          cJSON_IsString(name_node) ? name_node->valuestring : activity->id);
        activity->duration = (int)duration_node->valuedouble;

        /* Three-point estimates default to `duration` (a single-point
         * estimate collapses PERT to plain CPM: expected = duration,
         * variance = 0). */
        activity->optimistic  = optimistic_node  ? (int)optimistic_node->valuedouble  : activity->duration;
        activity->most_likely = most_likely_node ? (int)most_likely_node->valuedouble : activity->duration;
        activity->pessimistic = pessimistic_node ? (int)pessimistic_node->valuedouble : activity->duration;

        pending_deps[i] = deps_node;
    }
    graph->count = count;

    /* Second pass: ids resolve to indices only once all activities exist. */
    for (int i = 0; i < count; ++i) {
        const cJSON *deps_node = pending_deps[i];
        if (!deps_node) continue;

        int num_deps = cJSON_GetArraySize(deps_node);
        if (num_deps > CPM_MAX_DEPS) {
            fprintf(stderr, "parse: activity '%s' has %d deps (max %d)\n",
                    graph->items[i].id, num_deps, CPM_MAX_DEPS);
            goto done;
        }
        for (int k = 0; k < num_deps; ++k) {
            cJSON *dep_node = cJSON_GetArrayItem(deps_node, k);
            if (!cJSON_IsString(dep_node) || !dep_node->valuestring) {
                fprintf(stderr, "parse: activity '%s' dependency[%d] is not a string\n",
                        graph->items[i].id, k);
                goto done;
            }
            int dep_index = graph_find_id(graph, dep_node->valuestring);
            if (dep_index < 0) {
                fprintf(stderr, "parse: activity '%s' depends on unknown id '%s'\n",
                        graph->items[i].id, dep_node->valuestring);
                goto done;
            }
            if (dep_index == i) {
                fprintf(stderr, "parse: activity '%s' depends on itself\n", graph->items[i].id);
                goto done;
            }
            graph->items[i].deps[graph->items[i].num_deps++] = dep_index;
        }
    }

    ok = true;

done:
    free(pending_deps);
    cJSON_Delete(root);
    if (!ok) graph_free(graph);
    return ok;
}

bool graph_validate(const Graph *graph) {
    if (!graph || graph->count <= 0) {
        fprintf(stderr, "parse: graph is empty\n");
        return false;
    }
    for (int i = 0; i < graph->count; ++i) {
        if (graph->items[i].id[0] == '\0') {
            fprintf(stderr, "parse: activity[%d] has empty id\n", i);
            return false;
        }
        if (graph->items[i].duration < 0) {
            fprintf(stderr, "parse: activity '%s' has negative duration\n", graph->items[i].id);
            return false;
        }
        if (graph->items[i].optimistic < 0
            || graph->items[i].optimistic > graph->items[i].most_likely
            || graph->items[i].most_likely > graph->items[i].pessimistic) {
            fprintf(stderr,
                "parse: activity '%s' PERT estimates must satisfy 0 <= optimistic <= most_likely <= pessimistic\n",
                graph->items[i].id);
            return false;
        }
        for (int j = i + 1; j < graph->count; ++j) {
            if (strcmp(graph->items[i].id, graph->items[j].id) == 0) {
                fprintf(stderr, "parse: duplicate activity id '%s'\n", graph->items[i].id);
                return false;
            }
        }
    }
    return true;
}

bool graph_topological_sort(Graph *graph) {
    if (!graph || graph->count <= 0) return false;
    int count = graph->count;

    int *in_degree         = calloc((size_t)count, sizeof(int));
    int *queue             = malloc((size_t)count * sizeof(int));
    int *order             = malloc((size_t)count * sizeof(int));
    int *successor_offsets = calloc((size_t)(count + 1), sizeof(int));
    int *successors        = NULL;
    int *write_cursor      = NULL;
    bool ok = false;

    if (!in_degree || !queue || !order || !successor_offsets) goto done;

    int total_edges = 0;
    for (int node = 0; node < count; ++node) {
        in_degree[node] = graph->items[node].num_deps;
        total_edges += graph->items[node].num_deps;
        for (int k = 0; k < graph->items[node].num_deps; ++k) {
            successor_offsets[graph->items[node].deps[k] + 1] += 1;
        }
    }
    for (int i = 1; i <= count; ++i) successor_offsets[i] += successor_offsets[i - 1];

    successors   = malloc((size_t)(total_edges > 0 ? total_edges : 1) * sizeof(int));
    write_cursor = calloc((size_t)count, sizeof(int));
    if (!successors || !write_cursor) goto done;

    for (int node = 0; node < count; ++node) {
        for (int k = 0; k < graph->items[node].num_deps; ++k) {
            int predecessor = graph->items[node].deps[k];
            successors[successor_offsets[predecessor] + write_cursor[predecessor]++] = node;
        }
    }

    int queue_head = 0, queue_tail = 0;
    for (int node = 0; node < count; ++node) {
        if (in_degree[node] == 0) queue[queue_tail++] = node;
    }

    int produced = 0;
    while (queue_head < queue_tail) {
        int node = queue[queue_head++];
        order[produced++] = node;
        for (int k = successor_offsets[node]; k < successor_offsets[node + 1]; ++k) {
            int successor = successors[k];
            if (--in_degree[successor] == 0) queue[queue_tail++] = successor;
        }
    }

    if (produced != count) {
        fprintf(stderr, "parse: cycle detected (sorted %d of %d activities)\n", produced, count);
        goto done;
    }

    /* topo_rank = longest path from any source, so layout columns reflect depth. */
    for (int i = 0; i < count; ++i) graph->items[i].topo_rank = 0;
    for (int i = 0; i < count; ++i) {
        int node = order[i];
        int max_rank = 0;
        for (int k = 0; k < graph->items[node].num_deps; ++k) {
            int rank = graph->items[graph->items[node].deps[k]].topo_rank + 1;
            if (rank > max_rank) max_rank = rank;
        }
        graph->items[node].topo_rank = max_rank;
    }

    free(graph->topo_order);
    graph->topo_order = order;
    order = NULL;
    ok = true;

done:
    free(in_degree);
    free(queue);
    free(order);
    free(successor_offsets);
    free(successors);
    free(write_cursor);
    return ok;
}
