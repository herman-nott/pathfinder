#include "../../inc/pathfinder.h"

t_vertex *get_by_index(t_vertex *list, int index)
{
    t_vertex *node = list;

    while (node)
    {
        if (node->index == index)
            return node;

        node = node->next;
    }

    return NULL;
}
