#include "../../inc/pathfinder.h"

char **add_str_to_arr(char **arr, const char *str)
{
    int size = 0;

    if (arr != NULL)
        while (arr[size] != NULL)
            size++;

    char **new_arr = (char **)malloc((size + 2) * sizeof(char *));
    for (int i = 0; i < size; i++)
        new_arr[i] = mx_strdup(arr[i]);

    new_arr[size] = mx_strdup(str);

    new_arr[size + 1] = NULL;

    mx_del_strarr(&arr);

    return new_arr;
}
