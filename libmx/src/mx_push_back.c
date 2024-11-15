#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data)
{
    if (!*list)
    {
        *list = mx_create_node(data);
        return;
    }
    else
    {
        t_list *new_node = *list;

        while (new_node->next)
        {
            new_node = new_node->next;
        }
        
        new_node->next = mx_create_node(data);
    }
}
