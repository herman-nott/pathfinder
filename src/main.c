#include "../inc/pathfinder.h"

int main(int argc, char const *argv[])
{
    check_arguments(argc);
    t_graf *graf = parse(argv[1]);

    for (int i = 0; i < graf->number_of_islands - 1; i++)
    {
        t_vertex *path = dijkstra(graf->adj_matrix, i, graf->number_of_islands);
        print(graf->adj_matrix, graf->islands_names, &path);
        clear_vertex_list(&path);
    }
    release_memory(graf);

    return 0;
}
