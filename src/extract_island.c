#include "../inc/pathfinder.h"

char *extract_island1(const char *line) {
    char *dash_pos = mx_strchr(line, '-');
    return mx_strndup(line, dash_pos - line);
}

char *extract_island2(const char *line) {
    char *dash_pos = mx_strchr(line, '-');
    char *comma_pos = mx_strchr(line, ',');
    return mx_strndup(dash_pos + 1, comma_pos - dash_pos - 1);
}
