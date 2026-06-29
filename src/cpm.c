#include "cpm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max_int(int a, int b) { return a > b ? a : b; }

/* Build flat successor adjacency: succ[succ_off[u] .. succ_off[u+1]) lists
 * the indices of activities that depend on u. Single allocation keeps both
 * arrays in one block so the caller frees once. */
static bool build_successors(const Graph *g, int **out_off, int **out_succ) {
    int n = g->count;
    int *off = calloc((size_t)(n + 1), sizeof(int));
    if (!off) return false;

    int edges = 0;
    for (int v = 0; v < n; ++v) {
        for (int k = 0; k < g->items[v].num_deps; ++k) off[g->items[v].deps[k] + 1] += 1;
        edges += g->items[v].num_deps;
    }
    for (int i = 1; i <= n; ++i) off[i] += off[i - 1];

    int *succ = malloc((size_t)max_int(edges, 1) * sizeof(int));
    if (!succ) { free(off); return false; }

    int *cursor = calloc((size_t)n, sizeof(int));
    if (!cursor) { free(off); free(succ); return false; }
    for (int v = 0; v < n; ++v) {
        for (int k = 0; k < g->items[v].num_deps; ++k) {
            int u = g->items[v].deps[k];
            succ[off[u] + cursor[u]++] = v;
        }
    }
    free(cursor);

    *out_off = off;
    *out_succ = succ;
    return true;
}

bool cpm_compute(Graph *g) {
    if (!g || g->count <= 0 || !g->topo_order) return false;
    int n = g->count;

    int project_duration = 0;
    for (int p = 0; p < n; ++p) {
        Activity *a = &g->items[g->topo_order[p]];
        int es = 0;
        for (int k = 0; k < a->num_deps; ++k) {
            int ef = g->items[a->deps[k]].ef;
            if (ef > es) es = ef;
        }
        a->es = es;
        a->ef = es + a->duration;
        if (a->ef > project_duration) project_duration = a->ef;
    }
    g->project_duration = project_duration;

    int *succ_off = NULL, *succ = NULL;
    if (!build_successors(g, &succ_off, &succ)) return false;

    for (int p = n - 1; p >= 0; --p) {
        int u = g->topo_order[p];
        Activity *a = &g->items[u];
        int start = succ_off[u], end = succ_off[u + 1];

        int lf = project_duration;
        for (int k = start; k < end; ++k) {
            int ls = g->items[succ[k]].ls;
            if (k == start || ls < lf) lf = ls;
        }
        a->lf = lf;
        a->ls = lf - a->duration;
        a->slack = a->ls - a->es;
        a->is_critical = (a->slack == 0);
    }

    free(succ_off);
    free(succ);
    return true;
}

void cpm_print_table(const Graph *g) {
    if (!g || g->count <= 0) { printf("(empty graph)\n"); return; }

    int w_id = 2, w_name = 4;
    for (int i = 0; i < g->count; ++i) {
        w_id   = max_int(w_id,   (int)strlen(g->items[i].id));
        w_name = max_int(w_name, (int)strlen(g->items[i].name));
    }

    printf("\n%-*s  %-*s  %5s  %4s  %4s  %4s  %4s  %5s  %s\n",
           w_id, "ID", w_name, "Name", "Dur", "ES", "EF", "LS", "LF", "Slack", "Crit");
    int dash_len = w_id + w_name + 36;
    for (int i = 0; i < dash_len; ++i) putchar('-');
    putchar('\n');

    for (int p = 0; p < g->count; ++p) {
        int i = g->topo_order ? g->topo_order[p] : p;
        const Activity *a = &g->items[i];
        printf("%-*s  %-*s  %5d  %4d  %4d  %4d  %4d  %5d  %s\n",
               w_id, a->id, w_name, a->name,
               a->duration, a->es, a->ef, a->ls, a->lf, a->slack,
               a->is_critical ? "*" : "");
    }
    printf("\nProject duration: %d\n\n", g->project_duration);
}
