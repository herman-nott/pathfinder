#include "../inc/pathfinder.h"

static bool is_island_in_list(char **islands_names, int count, const char *island)
{
    for (int i = 0; i < count; i++)
    {
        if (mx_strcmp(islands_names[i], island) == 0)
            return true;
    }
    
    return false;
}

static char **parse_islands_names(char **lines, int num_islands)
{
    char **islands_names = (char **)malloc(sizeof(char *) * (num_islands + 1));
    int count = 0;

    int num_lines = 0;
    while (lines[num_lines])
        num_lines++;

    for (int i = 1; i < num_lines; i++)
    {
        char **parts = mx_strsplit(lines[i], ',');
        char **islands_pair = mx_strsplit(parts[0], '-');

        char *island_1 = islands_pair[0];
        char *island_2 = islands_pair[1];

        if (!is_island_in_list(islands_names, count, island_1))
        {
            islands_names[count] = mx_strdup(island_1);
            count++;
        }
        
        if (!is_island_in_list(islands_names, count, island_2))
        {
            islands_names[count] = mx_strdup(island_2);
            count++;
        }

        mx_del_strarr(&parts);
        mx_del_strarr(&islands_pair);
    }
    
    islands_names[count] = NULL;
    return islands_names;
}

static int get_island_index(char **islands_names, int num_islands, const char *island)
{
    for (int i = 0; i < num_islands; i++)
    {
        if (mx_strcmp(islands_names[i], island) == 0)
            return i;
    }

    return -1;
}

static int **parse_adj_matrix(char **lines, int num_islands, char **islands_names)
{
    int **adj_matrix = (int **)malloc(sizeof(int *) * num_islands);

    int num_lines = 0;
    while (lines[num_lines])
        num_lines++;

    for (int i = 0; i < num_islands; i++)
    {
        adj_matrix[i] = (int *)malloc(sizeof(int *) * num_islands);
        for (int j = 0; j < num_islands; j++)
            adj_matrix[i][j] = (i == j) ? 0 : /* INT_MAX */ -1;
    }
    
    for (int i = 1; i < num_lines; i++)
    {
        char **parts = mx_strsplit(lines[i], ',');
        char **islands_pair = mx_strsplit(parts[0], '-');

        char *island_1 = islands_pair[0];
        char *island_2 = islands_pair[1];

        int distance = mx_atoi(parts[1]);

        int idx_1 = get_island_index(islands_names, num_islands, island_1);
        int idx_2 = get_island_index(islands_names, num_islands, island_2);

        adj_matrix[idx_1][idx_2] = distance;
        adj_matrix[idx_2][idx_1] = distance;

        mx_del_strarr(&parts);
        mx_del_strarr(&islands_pair);
    }

    return adj_matrix;
}

t_graf *parse(const char *filename)
{
    char *data = mx_file_to_str(filename);
    errors(data, filename);

    char **lines = mx_strsplit(data, '\n');
    
    t_graf *graf = (t_graf *)malloc(sizeof(t_graf));
    if (!graf)
        return NULL;
    
    graf->number_of_islands = mx_atoi(lines[0]);
    graf->islands_names = parse_islands_names(lines, graf->number_of_islands);
    graf->adj_matrix = parse_adj_matrix(lines, graf->number_of_islands, graf->islands_names);

    mx_del_strarr(&lines);
    free(data);

    return graf;
}
