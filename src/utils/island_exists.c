#include "../../inc/pathfinder.h"

bool island_exists(char **islands, const char *island)
{
    if (islands == NULL)
        return false;

    for (int i = 0; islands[i] != NULL; i++)
        if (mx_strcmp(islands[i], island) == 0)
            return true;
        
    return false;
}
