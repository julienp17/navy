/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** grid_destroy
*/

#include <stdlib.h>
#include "grid.h"

void grid_destroy(grid_t grid)
{
    for (unsigned int i = 0 ; i < GRID_SIZE ; i++)
        free(grid[i]);
    free(grid);
}