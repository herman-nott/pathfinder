#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data)
{
    if (!*list)
    {
        *list = mx_create_node(data);
        return;
    }
    else
    {
        t_list *new_node = mx_create_node(data);
        new_node->next = *list;
        *list = new_node;
    }
}
