#include "../inc/libmx.h"

void mx_printint(int n)
{
    long number = n;
    char numbers_array[20];
    int i = 0;

    if (number == 0)
    {
        mx_printchar('0');
    }
    else
    {
        if (number < 0)
        {
            mx_printchar('-');
            number *= -1;
        }

        while (number != 0)
        {
            numbers_array[i++] = number % 10 + '0';
            number /= 10;
        }
        
        while (--i >= 0)
        {
            mx_printchar(numbers_array[i]);
        }
    }
}
