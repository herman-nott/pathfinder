#include "../../inc/pathfinder.h"

void check_validate_distance(char *distance_str, int line, char **file, char *data, char *names)
{
    if (mx_strlen(distance_str) < 1
    || mx_strlen(distance_str) > 10
    || mx_atoi(distance_str) < 0)
    {
        free(names);
        free(distance_str);
        mx_del_strarr(&file);
        free(data);
        print_line_error(line);
    }

    for (int i = 0; distance_str[i]; i++)
    {
        if (!mx_isdigit(distance_str[i]))
        {
            free(names);
            free(distance_str);
            mx_del_strarr(&file);
            free(data);
            print_line_error(line);
        }
    }
}
