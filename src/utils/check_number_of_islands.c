#include "../../inc/pathfinder.h"

void check_number_of_islands(int given_n, int real_n, char **file, char *data)
{
    if (given_n != real_n)
    {
        mx_del_strarr(&file);
        free(data);
        mx_print_error("error: invalid number of islands\n");
        exit(-1);
    }
}
