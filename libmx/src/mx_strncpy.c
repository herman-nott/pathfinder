#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    if (len <= 0)
    {
        // dst[0] = '\0';
        return dst;
    }
    else
    {
        int i = 0;

        while (i < len && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }

        while (i < len)
        {
            dst[i] = '\0';
            i++;
        }

        return dst;
    }
}
