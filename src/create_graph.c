#include "../inc/pathfinder.h"

t_graph *create_graph(int num_islands) {
    t_graph *graph = malloc(sizeof(t_graph));
    graph->num_islands = num_islands;
    graph->islands = malloc(sizeof(char *) * num_islands);
    graph->adj_matrix = malloc(sizeof(int *) * num_islands);
    for (int i = 0; i < num_islands; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_islands);
        for (int j = 0; j < num_islands; j++) {
            graph->adj_matrix[i][j] = INT_MAX; // Initialize with "infinity"
        }
    }
    return graph;
}
