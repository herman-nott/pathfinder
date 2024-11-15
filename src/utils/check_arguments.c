#include "../../inc/pathfinder.h"

void check_arguments(int argc)
{
    if (argc != 2)
    {
        mx_print_error("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
}
