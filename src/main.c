#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printstr("Usage: ./pathfinder [filename]\n");
        return 1;
    }

    char *file_content = mx_file_to_str(argv[1]);
    t_graph *graph = parse_file(file_content);

    find_and_print_paths(graph);

    free_graph(graph);
    free(file_content);

    return 0;
}
