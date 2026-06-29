#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

static char *read_file(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "parse: cannot open '%s'\n", path); return NULL; }

    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return NULL; }
    long len = ftell(f);
    if (len < 0) { fclose(f); return NULL; }
    rewind(f);

    char *buf = malloc((size_t)len + 1);
    if (!buf) { fclose(f); return NULL; }
    size_t n = fread(buf, 1, (size_t)len, f);
    fclose(f);
    if ((long)n != len) { free(buf); return NULL; }
    buf[len] = '\0';
    return buf;
}

static void copy_string_field(char *dst, size_t dst_sz, const char *src) {
    if (!src) { dst[0] = '\0'; return; }
    size_t n = strlen(src);
    if (n >= dst_sz) n = dst_sz - 1;
    memcpy(dst, src, n);
    dst[n] = '\0';
}

static bool ensure_capacity(Graph *g, int needed) {
    if (g->capacity >= needed) return true;
    int new_cap = g->capacity ? g->capacity * 2 : 8;
    while (new_cap < needed) new_cap *= 2;
    Activity *p = realloc(g->items, (size_t)new_cap * sizeof(Activity));
    if (!p) return false;
    g->items = p;
    g->capacity = new_cap;
    return true;
}

void graph_init(Graph *g) {
    g->items = NULL;
    g->count = 0;
    g->capacity = 0;
    g->topo_order = NULL;
    g->project_duration = 0;
}

void graph_free(Graph *g) {
    if (!g) return;
    free(g->items);
    free(g->topo_order);
    graph_init(g);
}

int graph_find_id(const Graph *g, const char *id) {
    if (!g || !id) return -1;
    for (int i = 0; i < g->count; ++i) {
        if (strcmp(g->items[i].id, id) == 0) return i;
    }
    return -1;
}

bool graph_load_from_json(const char *path, Graph *g) {
    graph_init(g);

    char *text = read_file(path);
    if (!text) return false;

    cJSON *root = cJSON_Parse(text);
    free(text);
    if (!root) {
        const char *ep = cJSON_GetErrorPtr();
        fprintf(stderr, "parse: JSON parse error near: %s\n", ep ? ep : "(unknown)");
        return false;
    }

    const cJSON **pending = NULL;
    bool ok = false;

    cJSON *arr = cJSON_GetObjectItemCaseSensitive(root, "activities");
    if (!cJSON_IsArray(arr)) {
        fprintf(stderr, "parse: missing top-level 'activities' array\n");
        goto done;
    }

    int n = cJSON_GetArraySize(arr);
    if (!ensure_capacity(g, n)) {
        fprintf(stderr, "parse: out of memory (need %d activities)\n", n);
        goto done;
    }

    pending = calloc((size_t)n, sizeof(*pending));
    if (!pending) goto done;

    for (int i = 0; i < n; ++i) {
        cJSON *item = cJSON_GetArrayItem(arr, i);
        if (!cJSON_IsObject(item)) {
            fprintf(stderr, "parse: activity[%d] is not an object\n", i);
            goto done;
        }

        cJSON *jid       = cJSON_GetObjectItemCaseSensitive(item, "id");
        cJSON *jname     = cJSON_GetObjectItemCaseSensitive(item, "name");
        cJSON *jduration = cJSON_GetObjectItemCaseSensitive(item, "duration");
        cJSON *jdeps     = cJSON_GetObjectItemCaseSensitive(item, "dependencies");

        if (!cJSON_IsString(jid) || !jid->valuestring) {
            fprintf(stderr, "parse: activity[%d] missing string 'id'\n", i);
            goto done;
        }
        if (!cJSON_IsNumber(jduration)) {
            fprintf(stderr, "parse: activity '%s' missing numeric 'duration'\n", jid->valuestring);
            goto done;
        }
        if (jdeps && !cJSON_IsArray(jdeps)) {
            fprintf(stderr, "parse: activity '%s' 'dependencies' must be an array\n", jid->valuestring);
            goto done;
        }

        Activity *a = &g->items[i];
        memset(a, 0, sizeof(*a));
        copy_string_field(a->id, sizeof(a->id), jid->valuestring);
        copy_string_field(a->name, sizeof(a->name),
                          cJSON_IsString(jname) ? jname->valuestring : a->id);
        a->duration = (int)jduration->valuedouble;
        pending[i] = jdeps;
    }
    g->count = n;

    /* Second pass: ids resolve to indices only once all activities exist. */
    for (int i = 0; i < n; ++i) {
        const cJSON *jdeps = pending[i];
        if (!jdeps) continue;

        int dn = cJSON_GetArraySize(jdeps);
        if (dn > CPM_MAX_DEPS) {
            fprintf(stderr, "parse: activity '%s' has %d deps (max %d)\n",
                    g->items[i].id, dn, CPM_MAX_DEPS);
            goto done;
        }
        for (int k = 0; k < dn; ++k) {
            cJSON *jd = cJSON_GetArrayItem(jdeps, k);
            if (!cJSON_IsString(jd) || !jd->valuestring) {
                fprintf(stderr, "parse: activity '%s' dependency[%d] is not a string\n",
                        g->items[i].id, k);
                goto done;
            }
            int idx = graph_find_id(g, jd->valuestring);
            if (idx < 0) {
                fprintf(stderr, "parse: activity '%s' depends on unknown id '%s'\n",
                        g->items[i].id, jd->valuestring);
                goto done;
            }
            if (idx == i) {
                fprintf(stderr, "parse: activity '%s' depends on itself\n", g->items[i].id);
                goto done;
            }
            g->items[i].deps[g->items[i].num_deps++] = idx;
        }
    }

    ok = true;

done:
    free(pending);
    cJSON_Delete(root);
    if (!ok) graph_free(g);
    return ok;
}

bool graph_validate(const Graph *g) {
    if (!g || g->count <= 0) {
        fprintf(stderr, "parse: graph is empty\n");
        return false;
    }
    for (int i = 0; i < g->count; ++i) {
        if (g->items[i].id[0] == '\0') {
            fprintf(stderr, "parse: activity[%d] has empty id\n", i);
            return false;
        }
        if (g->items[i].duration < 0) {
            fprintf(stderr, "parse: activity '%s' has negative duration\n", g->items[i].id);
            return false;
        }
        for (int j = i + 1; j < g->count; ++j) {
            if (strcmp(g->items[i].id, g->items[j].id) == 0) {
                fprintf(stderr, "parse: duplicate activity id '%s'\n", g->items[i].id);
                return false;
            }
        }
    }
    return true;
}

bool graph_topological_sort(Graph *g) {
    if (!g || g->count <= 0) return false;
    int n = g->count;

    int *indeg = calloc((size_t)n, sizeof(int));
    int *queue = malloc((size_t)n * sizeof(int));
    int *order = malloc((size_t)n * sizeof(int));
    int *succ_off = calloc((size_t)(n + 1), sizeof(int));
    int *succ = NULL;
    int *cursor = NULL;
    bool ok = false;

    if (!indeg || !queue || !order || !succ_off) goto done;

    int total_edges = 0;
    for (int v = 0; v < n; ++v) {
        indeg[v] = g->items[v].num_deps;
        total_edges += g->items[v].num_deps;
        for (int k = 0; k < g->items[v].num_deps; ++k) succ_off[g->items[v].deps[k] + 1] += 1;
    }
    for (int i = 1; i <= n; ++i) succ_off[i] += succ_off[i - 1];

    succ = malloc((size_t)(total_edges > 0 ? total_edges : 1) * sizeof(int));
    cursor = calloc((size_t)n, sizeof(int));
    if (!succ || !cursor) goto done;

    for (int v = 0; v < n; ++v) {
        for (int k = 0; k < g->items[v].num_deps; ++k) {
            int u = g->items[v].deps[k];
            succ[succ_off[u] + cursor[u]++] = v;
        }
    }

    int qhead = 0, qtail = 0;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) queue[qtail++] = i;

    int produced = 0;
    while (qhead < qtail) {
        int u = queue[qhead++];
        order[produced++] = u;
        for (int k = succ_off[u]; k < succ_off[u + 1]; ++k) {
            int v = succ[k];
            if (--indeg[v] == 0) queue[qtail++] = v;
        }
    }

    if (produced != n) {
        fprintf(stderr, "parse: cycle detected (sorted %d of %d activities)\n", produced, n);
        goto done;
    }

    /* topo_rank = longest path from any source, so layout columns reflect depth. */
    for (int i = 0; i < n; ++i) g->items[i].topo_rank = 0;
    for (int p = 0; p < n; ++p) {
        int u = order[p];
        int max_rank = 0;
        for (int k = 0; k < g->items[u].num_deps; ++k) {
            int r = g->items[g->items[u].deps[k]].topo_rank + 1;
            if (r > max_rank) max_rank = r;
        }
        g->items[u].topo_rank = max_rank;
    }

    free(g->topo_order);
    g->topo_order = order;
    order = NULL;
    ok = true;

done:
    free(indeg);
    free(queue);
    free(order);
    free(succ_off);
    free(succ);
    free(cursor);
    return ok;
}
