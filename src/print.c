#include "../inc/pathfinder.h"

static void print_equals()
{
    for (int i = 0; i < 40; i++)
        mx_printchar('=');
    
    mx_printchar('\n');
}

static void print_path(char **islands_names, t_vertex *vertex, int source)
{
    mx_printstr("Path: ");
    mx_printstr(islands_names[source]);
    mx_printstr(" -> ");
    mx_printstr(islands_names[vertex->index]);
    mx_printchar('\n');
}

static int *print_route(char **islands_names, t_vertex *vertex)
{
    int *indices = parse_path(vertex->path);
    
    mx_printstr("Route: ");
    mx_printstr(islands_names[indices[1]]);
    for (int i = 2; i < indices[0]; i++)
    {
        mx_printstr(" -> ");
        mx_printstr(islands_names[indices[i]]);
    }
    mx_printchar('\n');

    return indices;
}

static void print_distance(int **adj_matrix, int *route, int distance)
{
    int i = 2;

    mx_printstr("Distance: ");
    mx_printint(adj_matrix[route[1]][route[2]]);
    if (i < route[0] - 1)
    {
        for (; i < route[0] - 1; i++)
        {
            mx_printstr(" + ");
            mx_printint(adj_matrix[route[i]][route[i + 1]]);
        }
        mx_printstr(" = ");
        mx_printint(distance);
        mx_printchar('\n');
    }
    else
        mx_printchar('\n');
}

void print(int **adj_matrix, char **islands_names, t_vertex **head)
{
    t_vertex *vertex = *head;
    if (!vertex)
        return;

    int source = vertex->index;
    int *route = NULL;
    unpack_multiples(head, vertex);
    sort_by_index(head);


    vertex = vertex->next;

    while (vertex->index <= source) vertex = vertex->next;

    while (vertex) {
        print_equals();
        print_path(islands_names, vertex, source);
        route = print_route(islands_names, vertex);
        print_distance(adj_matrix, route, vertex->distance);
        print_equals();
        free(route);
        vertex = vertex->next;
    }
}
