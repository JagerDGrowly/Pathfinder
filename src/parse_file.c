#include "../inc/pathfinder.h"

t_graph *parse_file(char *file_content) {
    char **lines = mx_strsplit(file_content, '\n');
    int num_islands = mx_atoi(lines[0]);
    t_graph *graph = create_graph(num_islands);

    for (int i = 1; lines[i]; i++) {
        char *island1 = extract_island1(lines[i]);
        char *island2 = extract_island2(lines[i]);
        int distance = extract_bridge_length(lines[i]);

        add_bridge(graph, island1, island2, distance);

        free(island1);
        free(island2);
    }

    mx_del_strarr(&lines);
    return graph;
}
