#include "../../inc/pathfinder.h"

void release_memory(t_graf *graf)
{
    for (int i = 0; i < graf->number_of_islands; i++)
    {
        free(graf->islands_names[i]);
        free(graf->adj_matrix[i]);
    }

    free(graf->adj_matrix);
    free(graf->islands_names);
    free(graf);
}
