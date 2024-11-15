#include "../../inc/pathfinder.h"

bool check_digit(const char *num)
{
    if(mx_strcmp(num, "") == 0)
        return false;

    if (num[0] == '0' && mx_strlen(num) > 1)
        return false;

    for (int i = 0; i < mx_strlen(num); i++)
        if (!mx_isdigit(num[i]))
            return false;

    if(mx_atoi(num) < 0)
        return false;
        
    return true;
}
