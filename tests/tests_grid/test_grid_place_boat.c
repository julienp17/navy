/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests to place a boat on a grid
*/

#include <criterion/criterion.h>
#include "grid.h"

Test(grid_place_boat, empty_grid)
{
    grid_t grid = NULL;
    int actual = 0;
    int expected = 0;

    grid = grid_create(8);
    actual = grid_place_boat(grid, "2:A1:A2");
    cr_assert_eq(actual, expected);
}

Test(grid_place_boat, four_boats_correctly_aligned)
{
    grid_t grid = NULL;
    int actual = 0;
    int expected = 0;

    grid = grid_create(8);
    actual = grid_place_boat(grid, "2:A1:B1");
    cr_assert_eq(actual, expected);
    actual = grid_place_boat(grid, "3:A2:C2");
    cr_assert_eq(actual, expected);
    actual = grid_place_boat(grid, "4:A3:D3");
    cr_assert_eq(actual, expected);
    actual = grid_place_boat(grid, "5:A4:E4");
    cr_assert_eq(actual, expected);
}

Test(grid_place_boat, bad_format)
{
    grid_t grid = NULL;
    int actual = 0;
    int expected = -1;

    grid = grid_create(8);
    actual = grid_place_boat(grid, "abcdef");
    cr_assert_eq(actual, expected);
}

Test(grid_place_boat, on_top_of_another_boat)
{
    grid_t grid = NULL;
    int actual = 0;
    int expected = 0;

    grid = grid_create(8);
    actual = grid_place_boat(grid, "4:A3:D3");
    cr_assert_eq(actual, expected);
    expected = -1;
    actual = grid_place_boat(grid, "3:B2:B4");
    cr_assert_eq(actual, expected);
}