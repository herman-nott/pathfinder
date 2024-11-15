#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL)
        return NULL;

    char *temp = mx_strtrim(str);
    char *res = mx_strnew(mx_strlen(temp));

    int i = 0, j = 0;
    while (temp[i] != '\0')
    {
        if (!mx_isspace(temp[i]) || (i > 0 && !mx_isspace(temp[i - 1])))
        {
            res[j] = temp[i];
            j++;
        }
        i++;
    }
    
    res[j] = '\0';

    mx_strdel(&temp);
    return res;
}
