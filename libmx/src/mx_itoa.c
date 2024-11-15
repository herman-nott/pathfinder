#include "../inc/libmx.h"

static int number_length(int num) 
{
    int len = 0;

    if (num < 0) 
    {
        len++;
        num = -num;
    }
    
    if (num == 0)
        return 1;

    while (num)
    {
        num /= 10;
        len++;
    }
    return len;
}

char *mx_itoa(int number)
{
	int len = number_length(number);
    // int tmp = number;
    char *result = NULL;

	result = mx_strnew(len);
    if (!result)
    {
        return NULL;
    }

	if (number == 0)
    {
        return mx_strcpy(result, "0");
    }
		
	if (number == -2147483648)
    {
        return mx_strcpy(result, "-2147483648");
    }
		
	int tmp = number < 0 ? -number : number;
    if (number < 0) 
    {
        result[0] = '-';
    }

    for (int i = len - 1; i >= (number < 0 ? 1 : 0); i--)
    {
        result[i] = (tmp % 10) + '0';
        tmp /= 10;
    }

	return result;
}
