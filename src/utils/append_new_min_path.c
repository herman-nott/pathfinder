#include "../../inc/pathfinder.h"

void append_new_min_path(t_vertex *vertex, t_vertex *adj_vertex)
{
    char *path = mx_strdup(adj_vertex->path);
    char *index_str = NULL;
    char *str = NULL;

    free(adj_vertex->path);

    index_str = mx_itoa(vertex->index);
    str = mx_strjoin("|", index_str);
    adj_vertex->path = mx_strjoin(path, str);
    
    free(index_str);
    free(str);
    free(path);
}
