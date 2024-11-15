#include "../../inc/pathfinder.h"

int count_nodes(t_vertex **head, int index)
{
	t_vertex *vertex = *head;
	int count = 0;

	while (vertex)
    {
		if (vertex->index == index)
			count++;
		vertex = vertex->next;
	}
	return count;
}
