#include "../inc/libmx.h"

void mx_pop_back(t_list **head)
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
        t_list *template = *head;

        while (template->next->next)
        {
            template = template->next;
        }
        
        free(template->next);
        template->next = NULL;
        template = NULL;
    }
}
