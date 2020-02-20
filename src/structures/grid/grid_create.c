/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Create and return a grid
*/

#include <stdlib.h>
#include "grid.h"
#include "my.h"

grid_t grid_create(unsigned int grid_size)
{
    grid_t grid = NULL;

    grid = malloc(sizeof(cell_t *) * (grid_size + 1));
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for grid enum\n");
        return (NULL);
    }
    for (unsigned int row = 0 ; row < grid_size ; row++) {
        grid[row] = malloc(sizeof(cell_t) * grid_size);
        for (unsigned int col = 0 ; col < grid_size ; col++)
            grid[row][col] = EMPTY;
    }
    grid[grid_size] = NULL;
    return (grid);
}