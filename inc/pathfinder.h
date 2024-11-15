#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>

// Structures
typedef struct s_graf t_graf;
typedef struct s_vertex t_vertex;

struct s_graf
{
    int number_of_islands;
    char **islands_names;
    int **adj_matrix;
};

struct s_vertex
{
    int index;
    int distance;
    char *path;
    t_vertex *next;
};

// Utils
    // additional
int strarr_len(char **str_arr);
void print_line_error(int i);
int count_unique_islands(char **file);
bool island_exists(char **islands, const char *island);
char **add_str_to_arr(char **arr, const char *str);
void update_path(t_vertex *vertex, t_vertex *adj_vertex);
void append_new_min_path(t_vertex *vertex, t_vertex *adj_vertex);
void clear_vertex_list(t_vertex **vertex_list);
void release_memory(t_graf *graf);
    // check input data
void check_arguments(int argc);
bool check_digit(const char *num);
void check_validate_names(char *names, int line, char **file, char *data, char *distance_str);
void check_validate_distance(char *distance_str, int line, char **file, char *data, char *names);
void check_empty_line(char **str_arr, char *file);
void check_extra_enter(char *data);
void check_number_of_islands(int given_n, int real_n, char **file, char *data);
void check_duplicate_bridges(char **lines, char *data);
void check_sum_of_bridges_lengths(char **lines, char *data);
    // work with vertex
t_vertex *create_vertex(int index, int distance, char *path);
t_vertex *push_back_vertex(t_vertex **list, int index, int distance, char *path);
t_vertex *get_by_index(t_vertex *list, int index);
t_vertex *pop_by_index(t_vertex **list, int index);
void sort_by_index(t_vertex **head_ptr);
void pop_front_vertex(t_vertex **list);
int count_nodes(t_vertex **head, int index);
t_vertex *push_next(t_vertex *vertex, int index, int distance, char *path);
    // print
int *parse_path(char *path);
void unpack_multiples(t_vertex **visited, t_vertex *vertex);

// Main functions
void errors(char *data, const char *filename);
t_graf *parse(const char *filename);
t_vertex *dijkstra(int **adj_matrix, int n, int root);
void print(int **adj_matrix, char **islands_names, t_vertex **head);

#endif
