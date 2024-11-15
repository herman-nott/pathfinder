#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    if (hex == NULL)
        return 0;
    
    unsigned long result = 0;
    int i = 0;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        i = 2;
    
    while (hex[i] != '\0')
    {
        char c = hex[i]; 
        result *= 16;

        if (mx_isdigit(c))
            result += c - '0';
        else if (mx_islower(c))
            result += c - 'a' + 10;
        else if (mx_isupper(c))
            result += c - 'A' + 10;
        else
            break;
        
        i++;
    }

    return result;
}
