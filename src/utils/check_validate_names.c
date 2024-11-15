#include "../../inc/pathfinder.h"

static bool isalphabetical(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void check_validate_names(char *names, int line, char **file, char *data, char *distance_str)
{
    int del_ind = mx_get_char_index(names, '-');
    if (del_ind < 1) {
        free(distance_str);
        free(names);
        mx_del_strarr(&file);
        free(data);
        print_line_error(line);
    }

    char *first = mx_strndup(names, del_ind);
    char *second = mx_strndup(names + del_ind + 1,
                              mx_strlen(names) - del_ind - 1);

    if (mx_strlen(first) < 1
    || mx_strlen(second) < 1
    || mx_strcmp(first, second) == 0) {
        free(first);
        free(second);

        free(names);
        free(distance_str);
        mx_del_strarr(&file);
        free(data);
        print_line_error(line);
    }

    for (int i = 0; i < mx_strlen(first); ++i)
    {
        if (!isalphabetical(first[i]))
        {
            free(first);
            free(second);

            free(names);
            free(distance_str);
            mx_del_strarr(&file);
            free(data);
            print_line_error(line);
        }
    }

    for (int i = 0; i < mx_strlen(second); ++i)
    {
        if (!isalphabetical(second[i]))
        {
            free(first);
            free(second);

            free(names);
            free(distance_str);
            mx_del_strarr(&file);
            free(data);
            print_line_error(line);
        }
    }

    free(first);
    free(second);
}
