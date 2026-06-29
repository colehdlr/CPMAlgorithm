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

    Activity  *activities = NULL;
    int       *topo_order = NULL;
    CPMResult *results    = NULL;
    int count = 0;
    int project_duration = 0;

    int exit_code = 1;
    if (!parse_load_from_json(path, &activities, &count)) goto done;
    if (!topological_sort(activities, count, &topo_order)) goto done;

    results = calloc((size_t)count, sizeof(CPMResult));
    if (!results) { fprintf(stderr, "main: out of memory\n"); goto done; }

    if (!cpm_compute(activities, count, topo_order, results, &project_duration)) {
        fprintf(stderr, "cpm: failed to compute schedule\n");
        goto done;
    }

    cpm_print_table(activities, count, topo_order, results, project_duration);
    if (show_window) {
        render_run(activities, count, topo_order, results, project_duration);
    }
    exit_code = 0;

done:
    free(activities);
    free(topo_order);
    free(results);
    return exit_code;
}
