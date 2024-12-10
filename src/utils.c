#include "../inc/pathfinder.h"

bool is_valid_bridge_line(const char *line) {
    int dash = mx_get_char_index(line, '-');
    int comma = mx_get_char_index(line, ',');

    if (dash < 1 || comma <= dash + 1 || comma == mx_strlen(line) - 1)
        return false;

    char *length_str = mx_strndup(line + comma + 1, mx_strlen(line) - comma - 1);
    if (!mx_isdigit(length_str[0])) {
        mx_strdel(&length_str);
        return false;
    }

    mx_strdel(&length_str);
    return true;
}
