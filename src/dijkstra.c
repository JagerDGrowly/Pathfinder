#include "../inc/pathfinder.h"

int dijkstra(t_graph *graph, int start, int end, int **distances, int **previous) {
    bool *visited = malloc(sizeof(bool) * graph->num_islands);

    // Initialize distances and visited arrays
    for (int i = 0; i < graph->num_islands; i++) {
        distances[start][i] = INT_MAX;  // Initialize all distances to infinity
        visited[i] = false;
        previous[start][i] = -1; // -1 indicates no previous node
    }

    distances[start][start] = 0;  // Start island has distance 0 to itself

    for (int i = 0; i < graph->num_islands; i++) {
        int min_distance = INT_MAX;
        int current = -1;

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < graph->num_islands; j++) {
            if (!visited[j] && distances[start][j] < min_distance) {
                min_distance = distances[start][j];
                current = j;
            }
        }

        // If no such node exists or we've reached the destination, stop
        if (current == -1 || current == end) {
            break;
        }

        visited[current] = true;

        // Update distances to neighbors and record the path
        for (int neighbor = 0; neighbor < graph->num_islands; neighbor++) {
            int weight = graph->adj_matrix[current][neighbor];
            if (weight != INT_MAX && !visited[neighbor]) {
                int new_distance = distances[start][current] + weight;
                if (new_distance < distances[start][neighbor]) {
                    distances[start][neighbor] = new_distance;
                    previous[start][neighbor] = current;  // Record the path
                }
            }
        }
    }

    free(visited);
    return distances[start][end]; // Return the final distance
}
