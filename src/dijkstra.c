#include "../inc/pathfinder.h"

static t_vertex *create_unvisited_list(int root, int n)
{
    char *root_str = mx_itoa(root);
    t_vertex *list = create_vertex(root, 0, root_str);
    if (!list) {
        free(root_str);
        return NULL;
    }
    int i = 0;

    while (i < n)
    {
        if (i == root)
        {
            i += 1;
            continue;
        }
        push_back_vertex(&list, i, -2, root_str);
        i++;
    }
    free(root_str);
    return list;
}

static int calc_index(t_vertex *unvisited)
{
    t_vertex *node = unvisited;
    int min_distance = INT_MAX;
    int index = -1;

    while (node)
    {
        if (node->distance > 0 && min_distance > node->distance)
        {
            min_distance = node->distance;
            index = node->index;
        }
        node = node->next;        
    }
    return index;
}

static void update_data(t_vertex *vertex, t_vertex *adj_vertex, int edge)
{
    if (adj_vertex->distance == -2 
        || vertex->distance + edge < adj_vertex->distance)
    {
        adj_vertex->distance = vertex->distance + edge;
        update_path(vertex, adj_vertex);
    }
    else if (vertex->distance + edge == adj_vertex->distance)
    {
        append_new_min_path(vertex, adj_vertex);
    }
}

static void analyse_adjacent(int **matrix, t_vertex *unvisited,
                             t_vertex *current_vertex, int n)
{
    t_vertex *vertex = NULL;
    int index = current_vertex->index;
    int i = 0;

    while (i < n)
    {
        if (matrix[index][i] > 0)
        {
            vertex = get_by_index(unvisited, i);
            if (vertex)
                update_data(current_vertex, vertex, matrix[index][i]);
        }
        i++;
    }
}

t_vertex *dijkstra(int **matrix, int root, int n)
{
    t_vertex *unvisited = create_unvisited_list(root, n);
    t_vertex *visited = NULL;
    t_vertex *vtx = NULL;

    while (unvisited && root != -1)
    {
        vtx = get_by_index(unvisited, root);
        analyse_adjacent(matrix, unvisited, vtx, n);
        push_back_vertex(&visited, vtx->index, vtx->distance, vtx->path);
        pop_by_index(&unvisited, root);
        root = calc_index(unvisited);
    }
    
    if (unvisited)
        clear_vertex_list(&unvisited);

    return visited;
}
