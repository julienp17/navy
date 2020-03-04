/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Print the grids to standard output
*/

#include "grid.h"
#include "my.h"

void print_grids(grid_t player_grid, grid_t enemy_grid)
{
    my_putstr("my positions:\n");
    grid_print(player_grid);
    my_putstr("\nenemy's positions:\n");
    grid_print(enemy_grid);
    my_putchar('\n');
}