#include "../inc/pathfinder.h"

void free_graph(t_graph *graph) {
    for (int i = 0; i < graph->num_islands; i++) {
        free(graph->islands[i]);
        free(graph->adj_matrix[i]);
    }
    free(graph->islands);
    free(graph->adj_matrix);
    free(graph);
}
