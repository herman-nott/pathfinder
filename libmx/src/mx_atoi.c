#include "../../inc/pathfinder.h"

int mx_atoi(const char *str)
{
    long long int result = 0;
    int sign = 1;

    while (mx_isspace(*str))
    {
        str++;
    }
    
    if (*str == '-' || *str == '+')
    {
        sign = (*str++ == '-') ? -1 : 1;
    }

    while (mx_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    if (result > 2147483647) return -1;

    return (int)(result * sign);
}
