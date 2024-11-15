#include "../../inc/pathfinder.h"

void check_extra_enter(char *data)
{
    int num_n = 0;

    for(int i = 0; i < mx_strlen(data); i++)
    {
        if(data[i] == '\n')
            num_n++;
        
        if(data[i] == '\n' && !mx_isalpha(data[i + 1]))
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(num_n + 1)); 
            mx_print_error(" is not valid\n");
            exit(-1);
        }
    }
}
