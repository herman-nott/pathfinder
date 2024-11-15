#include "../inc/pathfinder.h"

static void file_does_not_exist(char *data, const char *filename)
{
    if (data == NULL)
    {
        mx_print_error("error: file ");
        mx_print_error(filename);
        mx_print_error(" does not exist\n");
        free(data);
        exit(-1);
    }
}

static void file_is_empty(char *data, const char *filename)
{
    if (!data[0])
    {
        mx_print_error("error: file ");
        mx_print_error(filename);
        mx_print_error(" is empty\n");
        free(data);
        exit(-1);
    }
}

static void line_1_is_not_valid(char *data)
{
    if (data[0] == '\n')
    {
        mx_print_error("error: line 1 is not valid\n");
        free(data);
        exit(-1);
    }

    char *first_line_char = mx_strndup(data, mx_get_char_index(data, '\n'));
    int first_num_int = -1;

    if((check_digit(first_line_char) && mx_atoi(first_line_char) <= INT_MAX))
        first_num_int = mx_atoi(first_line_char);
    else
    {
        mx_print_error("error: line 1 is not valid\n");
        free(first_line_char);
        free(data);
        exit(-1);
    }
    if (first_num_int < 1) {
        mx_print_error("error: line 1 is not valid\n");
        free(first_line_char);
        free(data);
        exit(-1);
    }
    free(first_line_char);
}

static void line_is_not_valid(char *data)
{
    char **file = mx_strsplit(data, '\n');

    //check_extra_enter(data);
    check_empty_line(file, data);

    for (int i = 1; file[i]; i++)
    {
        int del_ind = mx_get_char_index(file[i], ',');
        if (del_ind < 3) {
            mx_del_strarr(&file);
            free(data);
            print_line_error(i);
        }
        char *names = mx_strndup(file[i], del_ind);
        char *length = mx_strndup(file[i] + del_ind + 1,
                                  mx_strlen(file[i]) - del_ind - 1);

        check_validate_names(names, i, file, data ,length);
        check_validate_distance(length, i, file, data, names);

        free(names);
        free(length);
    }

    mx_del_strarr(&file);
}

static void invalid_number_of_islands(char *data)
{
    char **file = mx_strsplit(data, '\n');

    int given_n = mx_atoi(file[0]);
    int real_n = count_unique_islands(file);
    check_number_of_islands(given_n, real_n, file, data);

    mx_del_strarr(&file);
}

static void duplicate_bridges(char *data)
{
    char **file = mx_strsplit(data, '\n');
    check_duplicate_bridges(file, data);
    mx_del_strarr(&file);
}

static void invalid_sum_of_briges_lengths(char *data)
{
    char **file = mx_strsplit(data, '\n');
    check_sum_of_bridges_lengths(file, data);
    mx_del_strarr(&file);
}

void errors(char *data, const char *filename)
{
    file_does_not_exist(data, filename);
    file_is_empty(data, filename);
    line_1_is_not_valid(data);
    line_is_not_valid(data);
    invalid_number_of_islands(data);
    duplicate_bridges(data);
    invalid_sum_of_briges_lengths(data);
}
