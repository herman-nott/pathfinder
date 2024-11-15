#include "../inc/libmx.h"

void mx_pop_front(t_list **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        t_list *template = (*head)->next;
        free(*head);
        *head = template;
    }
}
