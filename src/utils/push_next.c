#include "../../inc/pathfinder.h"

t_vertex *push_next(t_vertex *vertex, int index, int distance, char *path)
{
	t_vertex *new = create_vertex(index, distance, path);
	
	new->next = vertex->next;
	vertex->next = new;

	return new;
}
