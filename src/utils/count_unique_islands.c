#include "../../inc/pathfinder.h"

int count_unique_islands(char **file)
{
    char **islands = NULL;
    int count = 0;

    for (int i = 1; file[i]; i++)
    {
        char **str_arr = mx_strsplit(file[i], ',');
        char **island_names = mx_strsplit(str_arr[0], '-');
        
        if (!island_exists(islands, island_names[0]))
        {
            islands = add_str_to_arr(islands, island_names[0]);
            count++;
        }

        if (!island_exists(islands, island_names[1]))
        {
            islands = add_str_to_arr(islands, island_names[1]);
            count++;
        }

        mx_del_strarr(&str_arr);
        mx_del_strarr(&island_names);
    }

    mx_del_strarr(&islands);
    return count;
}
