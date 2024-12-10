#include "../inc/pathfinder.h"

void validate_file(char *file_content) {
    char **lines = mx_strsplit(file_content, '\n');
    int num_lines = mx_count_words(file_content, '\n');

    if (!mx_isdigit(lines[0][0])) {
        mx_printstr("error: line 1 is not valid\n");
        exit(1);
    }

    int num_islands = mx_atoi(lines[0]);
    if (num_islands <= 0) {
        mx_printstr("error: line 1 is not valid\n");
        exit(1);
    }

    unsigned long total_length = 0;
    for (int i = 1; i < num_lines; i++) {
        if (!is_valid_bridge_line(lines[i])) {
            mx_printstr("error: line ");
            mx_printint(i + 1);
            mx_printstr(" is not valid\n");
            exit(1);
        }

        int bridge_length = extract_bridge_length(lines[i]);
        total_length += bridge_length;
        if (total_length > INT_MAX) {
            mx_printstr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }

    mx_del_strarr(&lines);
}
