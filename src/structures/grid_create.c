/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Create and return a grid
*/

#include <stdlib.h>
#include "cell_state.h"
#include "my.h"

grid_t grid_create(unsigned int nb_rows, unsigned int nb_cols)
{
    grid_t grid = NULL;

    grid = malloc(sizeof(cell_t *) * (nb_rows + 1));
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for grid enum\n");
        return (NULL);
    }
    for (unsigned int row = 0 ; row < nb_rows ; row++) {
        grid[row] = malloc(sizeof(cell_t) * nb_cols);
        for (unsigned int col = 0 ; col < nb_cols ; col++)
            grid[row][col] = EMPTY;
    }
    grid[nb_rows] = NULL;
    return (grid);
}