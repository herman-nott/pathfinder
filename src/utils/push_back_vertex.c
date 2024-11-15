#include "../../inc/pathfinder.h"

t_vertex *push_back_vertex(t_vertex **list, int index, int distance, char *path)
{
    t_vertex *new_node = create_vertex(index, distance, path);
    t_vertex *node = NULL;

    if (list && *list)
    {
        node = *list;
        while (node->next)
            node = node->next;

        node->next = new_node;
    }
    else
        *list = new_node;

    return new_node;
}
