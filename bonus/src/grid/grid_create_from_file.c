/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Checks if a file is valid for navy positions
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "grid.h"
#include "navy.h"
#include "get_next_line.h"

static grid_t get_grid_from_fd(int fd);
static int fill_grid_by_lines(grid_t grid, int fd);
static bool line_is_valid(char const *line, int line_nb);
static char **get_lines(int fd);

grid_t grid_create_from_file(char const *filename)
{
    int fd = 0;
    grid_t grid = NULL;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        my_puterr("Couldn't open given file\n");
        return (NULL);
    }
    grid = get_grid_from_fd(fd);
    if (close(fd) == -1) {
        my_puterr("Couldn't close given file\n");
        return (NULL);
    }
    return (grid);
}

static grid_t get_grid_from_fd(int fd)
{
    grid_t grid = NULL;

    grid = grid_create(GRID_SIZE);
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for initial grid\n");
        return (NULL);
    }
    return ((fill_grid_by_lines(grid, fd) == -1) ? NULL : grid);
}

static int fill_grid_by_lines(grid_t grid, int fd)
{
    char **lines = NULL;

    lines = get_lines(fd);
    if (!lines) {
        my_puterr("Not enough lines in file\n");
        return (-1);
    }
    for (unsigned int i = 0 ; lines[i] ; i++) {
        if (!line_is_valid(lines[i], i)||grid_place_boat(grid, lines[i]) == -1){
            my_puterr("Unexpected line found in file area\n");
            return (-1);
        }
    }
    return (0);
}

static char **get_lines(int fd)
{
    char **lines = NULL;

    lines = malloc(sizeof(char *) * (NB_BOATS + 1));
    if (lines == NULL) {
        my_puterr("Couldn't allocate memory for lines\n");
        return (NULL);
    }
    for (unsigned int i = 0 ; i < NB_BOATS ; i++) {
        lines[i] = get_next_line(fd);
        if (lines[i] == NULL)
            return (NULL);
    }
    lines[NB_BOATS] = NULL;
    return (lines);
}

static bool line_is_valid(char const *line, int line_nb)
{
    int navy_lengths[] = {2, 3, 4, 5};

    return (line != NULL
            && line[0] - '0' == navy_lengths[line_nb]);
}