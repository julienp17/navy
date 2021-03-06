/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Place a boat in a grid
*/

#include <stddef.h>
#include "grid.h"
#include "my.h"
#include "format_parsing.h"

bool line_is_valid(char *line, int line_nb);
static int place_boat(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos);
static int place_boat_vertically(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos);
static int place_boat_horizontally(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos);

int grid_place_boat(grid_t grid, char const *format)
{
    char **args = NULL;
    int boat_len = 0;
    char *first_pos = NULL;
    char *last_pos = NULL;

    if (!format_is_valid(format))
        return (-1);
    args = my_str_to_word_array(format, SEP);
    boat_len = my_getnbr(args[0]);
    first_pos = args[1];
    last_pos = args[2];
    if (place_boat(grid, boat_len, first_pos, last_pos) == -1)
        return (-1);
    my_free_2d_array(args);
    return (0);
}

static int place_boat(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos)
{
    char first_letter = first_pos[0];
    char last_letter = last_pos[0];
    int (*place_boat_direction)(grid_t, int, char const *, char const *) = NULL;

    if (first_letter == last_letter)
        place_boat_direction = &place_boat_vertically;
    else
        place_boat_direction = &place_boat_horizontally;
    return (place_boat_direction(grid, boat_len, first_pos, last_pos));
}

static int place_boat_vertically(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos)
{
    char first_letter = first_pos[0];
    int first_number = first_pos[1] - '0';
    int last_number = last_pos[1] - '0';

    for (int i = first_number - 1 ; i < last_number ; i++)
        if (cell_is_boat(grid[i][first_letter - 'A']))
            return (-1);
    for (int i = first_number - 1 ; i < last_number ; i++)
        grid[i][first_letter - 'A'] = boat_len + '0';
    return (0);
}

static int place_boat_horizontally(grid_t grid, int boat_len,
                        char const *first_pos, char const *last_pos)
{
    char first_letter = first_pos[0];
    int first_number = first_pos[1] - '0';
    char last_letter = last_pos[0];

    for (int i = first_letter - 'A' ; i <= last_letter - 'A' ; i++)
        if (cell_is_boat(grid[first_number - 1][i]))
            return (-1);
    for (int i = first_letter - 'A' ; i <= last_letter - 'A' ; i++)
        grid[first_number - 1][i] = boat_len + '0';
    return (0);
}