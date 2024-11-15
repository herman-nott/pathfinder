#include "../../inc/pathfinder.h"

static void pop_vertex(t_vertex *node)
{
	t_vertex *tmp = node->next;

	node->next = node->next->next;		
	tmp->next = NULL;
    
	free(tmp->path);
	free(tmp);
}

t_vertex *pop_by_index(t_vertex **list, int index)
{
	if (!list || *list == NULL)
		return NULL;

	t_vertex *node = *list;

	if (node->index == index)
    {
		pop_front_vertex(list);
		return NULL;
	}

	while (node->next)
    {
		if (node->next->index == index)
        {
			pop_vertex(node);
			break;
		}
		node = node->next;
	}

	return node->next;
}
