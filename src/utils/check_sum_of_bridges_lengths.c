#include "../../inc/pathfinder.h"

void check_sum_of_bridges_lengths(char **lines, char *data)
{
    int num_lines = 0;
    while (lines[num_lines])
        num_lines++;

    long long total_distance = 0;

    for (int i = 1; i < num_lines; i++)
    {
        char **parts = mx_strsplit(lines[i], ',');
        if (parts[1])
        {
            int distance = mx_atoi(parts[1]);
            total_distance += distance;

            if (total_distance > INT_MAX)
            {
                mx_del_strarr(&lines);
                free(data);
                mx_print_error("error: sum of bridges lengths is too big\n");
                mx_del_strarr(&parts);
                exit(-1);
            }
        }

        mx_del_strarr(&parts);
    }
}
