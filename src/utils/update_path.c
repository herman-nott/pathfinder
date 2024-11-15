#include "../../inc/pathfinder.h"

void update_path(t_vertex *vertex, t_vertex *adj_vertex)
{
    char **strarr = mx_strsplit(vertex->path, '|');
    char *i_str = NULL;
    char *s1 = NULL;

    free(adj_vertex->path);
    
    i_str = mx_itoa(adj_vertex->index);
    s1 = mx_strjoin(strarr[0], "-");
    
    adj_vertex->path = mx_strjoin(s1, i_str);

    free(s1);
    free(i_str);

    if (strarr_len(strarr) != 1)
        append_new_min_path(vertex, adj_vertex);

    mx_del_strarr(&strarr);
}
