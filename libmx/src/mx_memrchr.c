#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    const unsigned char *last = (unsigned char *)s + n - 1;

    for (size_t i = 0; i < n; i++)
    {
        if (*last == (unsigned char)c)
            return (void *)last;
        last--;
    }
    
    return NULL;
}
