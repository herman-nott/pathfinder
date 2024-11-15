#include "../inc/libmx.h"

void mx_str_reverse(char *s)
{
    if (s == NULL || *s == '\0')
        return;

    char *end = s;
    while (*end != '\0')
    {
        end++;
    }
    end--;

    while (s < end)
    {
        char temp = *s;
        *s = *end;
        *end = temp;

        s++;
        end--;
    }
}
