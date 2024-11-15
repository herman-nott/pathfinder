#include "../../inc/pathfinder.h"

void check_empty_line(char **str_arr, char *file)
{
    int lines = mx_count_substr(file, "\n") + 1;
    int counter = 0;

    if (lines != strarr_len(str_arr))
    {
        counter = 0;
        for (int i = 1; file[i]; i++)
        {
            if (file[i] == '\n') 
                counter++;

            if (file[i - 1] == '\n' && file[i] == '\n')
            {
                mx_del_strarr(&str_arr);
                free(file);
                print_line_error(counter - 1);
            }
        }
    }
}
