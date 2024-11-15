#include "../inc/libmx.h"

static void swap(void **s1, void **s2) 
{
    void *template = *s1;
    *s1 = *s2;
    *s2 = template;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (!lst || !cmp)
        return NULL;

    bool swapped;
    t_list *ptr;
    t_list *last = NULL;

    do
    {
        swapped = false;
        ptr = lst;

        while (ptr->next != last)
        {
            if (cmp(ptr->data, ptr->next->data))
            {
                swap(&(ptr->data), &(ptr->next->data));
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
    
    return lst;
}
