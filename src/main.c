#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "cpm.h"
#include "render.h"

static void print_usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s [options] [activities.json]\n"
        "\n"
        "Loads a project network, runs the Critical Path Method on it, prints\n"
        "the result table, and opens a window visualising the graph.\n"
        "\n"
        "Options:\n"
        "  --no-render     Print the table only; don't open the window.\n"
        "  -h, --help      Show this message.\n"
        "\n"
        "If no path is given, 'data/activities.json' is used.\n",
        prog);
}

int main(int argc, char **argv) {
    const char *path = "data/activities.json";
    bool show_window = true;

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        }
        if (strcmp(arg, "--no-render") == 0) {
            show_window = false;
        } else if (arg[0] == '-') {
            fprintf(stderr, "unknown option: %s\n", arg);
            print_usage(argv[0]);
            return 2;
        } else {
            path = arg;
        }
    }

    Graph graph;
    graph_init(&graph);

    int exit_code = 1;
    if (!graph_load_from_json(path, &graph)) goto done;
    if (!graph_validate(&graph)) goto done;
    if (!graph_topological_sort(&graph)) goto done;
    if (!cpm_compute(&graph)) { fprintf(stderr, "cpm: failed to compute schedule\n"); goto done; }
    pert_compute(&graph);

    cpm_print_table(&graph);
    pert_print_table(&graph);
    if (show_window) render_run(&graph);
    exit_code = 0;

done:
    graph_free(&graph);
    return exit_code;
}
