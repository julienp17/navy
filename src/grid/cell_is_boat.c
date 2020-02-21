/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Returns true if the cell of a grid is a boat, false otherwise
*/

#include <stdbool.h>
#include "cell_state.h"

bool cell_is_boat(cell_t cell)
{
    return (cell != EMPTY
            && cell != HIT
            && cell != MISS);
}