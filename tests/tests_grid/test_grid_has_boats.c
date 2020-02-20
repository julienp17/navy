/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests to see if a grid still has boats
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "grid.h"

Test(grid_has_boats, empty_grid)
{
    grid_t grid = grid_create(8);
    bool has_boats = false;

    has_boats = grid_has_boats(grid);
    cr_assert_eq(has_boats, false);
}

Test(grid_has_boats, full_grid)
{
    grid_t grid = grid_create(8);
    bool has_boats = false;

    grid_place_boat(grid, "2:C1:C2");
    grid_place_boat(grid, "3:D4:F4");
    grid_place_boat(grid, "4:B5:B8");
    grid_place_boat(grid, "5:D7:H7");
    has_boats = grid_has_boats(grid);
    cr_assert_eq(has_boats, true);
}