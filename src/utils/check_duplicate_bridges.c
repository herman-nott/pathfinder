#include "../../inc/pathfinder.h"

void check_duplicate_bridges(char **lines, char *data)
{
    int num_lines = 0;
    while (lines[num_lines])
        num_lines++;

    for (int i = 1; i < num_lines; i++)
    {
        char *line1 = mx_strndup(lines[i], mx_get_char_index(lines[i], ','));
        for (int j = i + 1; j < num_lines; j++)
        {
            char *line2 = mx_strndup(lines[j], mx_get_char_index(lines[j], ','));

            if (mx_strcmp(line1, line2) == 0)
            {
                free(line1);
                free(line2);
                mx_del_strarr(&lines);
                free(data);
                mx_print_error("error: duplicate bridges\n");
                exit(-1);
            }

            free(line2);
        }

        free(line1);
    }
}
