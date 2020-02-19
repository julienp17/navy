/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Create and return a grid
*/

#include <stdlib.h>
#include "cell_state.h"
#include "my.h"

grid_t grid_create(unsigned int rows, unsigned int cols)
{
    grid_t grid = NULL;

    grid = malloc(sizeof(cell_t *) * (rows + 1));
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for grid enum\n");
        return (NULL);
    }
    for (unsigned int i = 0 ; i < rows ; i++) {
        grid[i] = malloc(sizeof(cell_t) * cols);
        for (unsigned int j = 0 ; j < cols ; j++)
            grid[i][j] = EMPTY;
    }
    grid[rows] = NULL;
    return (grid);
}