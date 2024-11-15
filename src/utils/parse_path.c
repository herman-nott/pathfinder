#include "../../inc/pathfinder.h"

int *parse_path(char *path)
{
    char **strarr = mx_strsplit(path, '-');
    int len = strarr_len(strarr) + 1;
    int *arr = malloc(sizeof(int) * len);
    int i = 1;
    
    arr[0] = len;
    while (i < len)
    {
        arr[i] = mx_atoi(strarr[i - 1]);
        i++;
    }

    mx_del_strarr(&strarr);
    return arr;
}
