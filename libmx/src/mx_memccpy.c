#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    if (dst == NULL || src == NULL)
        return NULL; 
        
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];

        if (s[i] == (unsigned char)c)
            return (void *)(d + i + 1);
    }

    return NULL;
}
