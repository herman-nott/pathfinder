#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c)
{
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        int count_words = mx_count_words(s, c);
        char **res = (char **)malloc(sizeof(char *) * (count_words + 1));
        
        if (res == NULL)
        {
            return NULL;
        }
        
        int j = 0;

        while (*s)
        {
            if (*s != c)
            {
                int word_len = 0;
                const char *start = s;
                while (*s && *s != c)
                {
                    word_len++;
                    s++;
                }

                char *new_word = mx_strnew(word_len);
                if (new_word == NULL)
                {
                    for (int k = 0; k < j; k++)
                    {
                        mx_strdel(&res[k]);
                    }
                    free(res);
                    return NULL;
                }

                mx_strncpy(new_word, start, word_len);
                res[j++] = new_word;
            }
            else
            {
                s++;
            }
        }

        res[j] = NULL;
        return res;
    }
}
