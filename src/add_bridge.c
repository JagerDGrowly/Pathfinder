#include "../inc/pathfinder.h"

void add_bridge(t_graph *graph, char *island1, char *island2, int distance) {
    int index1 = -1, index2 = -1;

    for (int i = 0; i < graph->num_islands; i++) {
        if (graph->islands[i] && mx_strcmp(graph->islands[i], island1) == 0) index1 = i;
        if (graph->islands[i] && mx_strcmp(graph->islands[i], island2) == 0) index2 = i;
    }

    if (index1 == -1) {
        for (int i = 0; i < graph->num_islands; i++) {
            if (graph->islands[i] == NULL) {
                graph->islands[i] = mx_strdup(island1);
                index1 = i;
                break;
            }
        }
    }

    if (index2 == -1) {
        for (int i = 0; i < graph->num_islands; i++) {
            if (graph->islands[i] == NULL) {
                graph->islands[i] = mx_strdup(island2);
                index2 = i;
                break;
            }
        }
    }

    graph->adj_matrix[index1][index2] = distance;
    graph->adj_matrix[index2][index1] = distance; // Since it's undirected
}
