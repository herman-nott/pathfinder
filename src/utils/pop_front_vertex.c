#include "../../inc/pathfinder.h"

void pop_front_vertex(t_vertex **list)
{
	if (list && *list)
    {
		t_vertex *node = *list;

		*list = node->next;
		node->next = NULL;

		free(node->path);
		free(node);
	}
}
