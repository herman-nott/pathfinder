#include "../../inc/pathfinder.h"

t_vertex *create_vertex(int index, int distance, char *path)
{
    t_vertex *node = malloc(sizeof(t_vertex));

    if (!node)
        return NULL;

    node->index = index;
    node->distance = distance;
    node->path = mx_strdup(path);
    node->next = NULL;

    return node;
}
