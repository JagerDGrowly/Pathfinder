#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../libmx/inc/libmx.h"

typedef struct s_graph {
    int num_islands;
    char **islands;
    int **adj_matrix;
} t_graph;

void validate_file(char *file_content);
bool is_valid_bridge_line(const char *line);

t_graph *parse_file(char *file_content);
void add_bridge(t_graph *graph, char *island1, char *island2, int distance);

t_graph *create_graph(int num_islands);
void free_graph(t_graph *graph);

void find_and_print_paths(t_graph *graph);
int dijkstra(t_graph *graph, int start, int end, int **distances, int **previous);

void print_path(t_graph *graph, int start, int end, int *distances);

char *extract_island1(const char *line);
char *extract_island2(const char *line);
int extract_bridge_length(const char *line);

#endif
