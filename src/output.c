#include "../inc/pathfinder.h"

void print_path(t_graph *graph, int start, int end, int *distances) {
    // Print the upper border
    mx_printstr("========================================\n");
    
    // Print the path header
    mx_printstr("Path: ");
    mx_printstr(graph->islands[start]);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]);
    mx_printstr("\n");
    
    // Print the route
    mx_printstr("Route: ");
    mx_printstr(graph->islands[start]);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]);
    mx_printstr("\n");
    
    // Print the total distance using the distances array
    mx_printstr("Distance: ");
    mx_printint(distances[end]); // Assuming distances[end] contains the shortest distance from start to end
    mx_printstr("\n");
    
    // Print the lower border
    mx_printstr("========================================\n");
}
