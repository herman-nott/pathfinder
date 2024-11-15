#include "../inc/libmx.h"

static int number_length(unsigned long num) 
{
    int len = 0;

    while (num)
    {
        num /= 16;
        len++;
    }
    return len;
}

char *mx_nbr_to_hex(unsigned long nbr)
{
    char *number = NULL;
    unsigned long n = nbr;
    int temp;
    int len = number_length(nbr);
    
    number = malloc(len + 1);
    if (number == NULL)
    {
        return NULL;
    }

    number[len] = '\0';

    if (nbr == 0)
    {
        return mx_strcpy(number, "0");
    }
    
    while (n)
    {
        temp = n % 16;
        if (temp < 10)
        {
            number[--len] = 48 + temp;
        }
        if (temp >= 10)
        {
            number[--len] = 87 + temp;
        }
        
        n /= 16;
    }
    
    return number;
}
