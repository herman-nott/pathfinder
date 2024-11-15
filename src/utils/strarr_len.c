#include "../../inc/pathfinder.h"

int strarr_len(char **str_arr)
{
    int len = 0;
    while (str_arr[len])
        len++;
        
    return len;
}
