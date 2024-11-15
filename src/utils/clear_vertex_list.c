#include "../../inc/pathfinder.h"

void clear_vertex_list(t_vertex **vertex_list)
{
    while (*vertex_list)
		pop_front_vertex(vertex_list);

	vertex_list = NULL;
}
