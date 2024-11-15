#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == NULL)
        {
            return -1;
        }
        
        for (int j = 0; j < size - 1; j++)
        {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0)
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int first = 0;
    int last = size - 1;
    int iterations = 0;

    while (first <= last)
    {
        iterations++;
        int mid = first + (last - first) / 2;
        int cmp = mx_strcmp(arr[mid], s);

        if (cmp == 0)
        {
            if (count != NULL)
                *count = iterations;
            
            return mid;
        }
        else if (cmp < 0)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }   
    }

    *count = 0;
    
    return -1;
}
