/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Returns true if the given grid has at least one boat, false otherwise
*/

#include <stdbool.h>
#include "grid.h"
#include "cell_state.h"

bool grid_has_boats(grid_t const grid)
{
    for (unsigned int i = 0 ; i < GRID_SIZE ; i++)
        for (unsigned int j = 0 ; j < GRID_SIZE ; j++)
            if (cell_is_boat(grid[i][j]))
                return (true);
    return (false);
}