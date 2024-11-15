#include "../inc/libmx.h"

static void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int mx_quicksort(char **arr, int left, int right)
{
    if (arr == NULL)
        return -1;
    
    int swap_count = 0;
    
    if (left < right)
    {
        int pivot_index = left + (right - left) / 2;
        char *pivot = arr[pivot_index];

        int i = left;
        int j = right;

        while (i <= j) {
            while (mx_strlen(arr[i]) < mx_strlen(pivot))
                i++;

            while (mx_strlen(arr[j]) > mx_strlen(pivot))
                j--;

            if (i <= j)
            {
                if (i != j && mx_strlen(arr[i]) != mx_strlen(arr[j]))
                {
                    swap(&arr[i], &arr[j]);
                    swap_count++;
                }
                i++;
                j--;
            }
        }
        
        swap_count += mx_quicksort(arr, left, j);
        swap_count += mx_quicksort(arr, i, right);
    }
    
    return swap_count;
}
