#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if (str == NULL)
        return -1;

    int counter = 0;
    int is_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            is_word = 0;
        }
        else if (is_word == 0)
        {
            is_word = 1;
            counter++;
        }
    }
    
    return counter;
}
