#include "../inc/libmx.h"

char *mx_strdup(const char *s1)
{
    if (s1 == NULL)
        return NULL;

    int len = mx_strlen(s1);
    
    char *dup = mx_strnew(len);
    if (dup == NULL)
        return NULL;

    mx_strcpy(dup, s1);

    return dup;
}
