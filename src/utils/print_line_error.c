#include "../../inc/pathfinder.h"

void print_line_error(int i)
{
    char *line = mx_itoa(i + 1);

    mx_print_error("error: line ");
    mx_print_error(line);
    mx_print_error(" is not valid\n");

    free(line);
    
    exit(-1);
}
