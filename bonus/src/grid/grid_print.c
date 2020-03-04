/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Print the grid
*/

#include "my.h"
#include "grid.h"

void grid_print(grid_t grid)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0 ; i < GRID_SIZE ; i++) {
        my_putchar('0' + (i + 1));
        my_putchar('|');
        for (int j = 0 ; j < GRID_SIZE ; j++) {
            my_putchar(grid[i][j]);
            if (j != GRID_SIZE - 1)
                my_putchar(' ');
        }
        my_putchar('\n');
    }
}