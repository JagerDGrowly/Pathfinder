#include "../inc/pathfinder.h"

void print_route(t_graph *graph, int *previous, int start, int end) {
    if (end == start) {
        mx_printstr(graph->islands[start]);
        return;
    }
    
    print_route(graph, previous, start, previous[end]);  // Recursive call
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]);
}

void find_and_print_paths(t_graph *graph) {
    int **distances = malloc(sizeof(int *) * graph->num_islands);
    int **previous = malloc(sizeof(int *) * graph->num_islands);

    for (int i = 0; i < graph->num_islands; i++) {
        distances[i] = malloc(sizeof(int) * graph->num_islands);
        previous[i] = malloc(sizeof(int) * graph->num_islands);
    }

    for (int i = 0; i < graph->num_islands; i++) {
        for (int j = i + 1; j < graph->num_islands; j++) {
            int distance = dijkstra(graph, i, j, distances, previous);

            // Print the path header
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(graph->islands[i]);
            mx_printstr(" -> ");
            mx_printstr(graph->islands[j]);
            mx_printstr("\n");

            // Print the route
            mx_printstr("Route: ");
            print_route(graph, previous[i], i, j);  // Print the route from i to j
            mx_printstr("\n");

            // Print the total distance
            mx_printstr("Distance: ");
            mx_printint(distance);  // Distance is already computed
            mx_printstr("\n");

            mx_printstr("========================================\n");
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < graph->num_islands; i++) {
        free(distances[i]);
        free(previous[i]);
    }
    free(distances);
    free(previous);
}
