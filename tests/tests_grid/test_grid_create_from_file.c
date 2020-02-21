/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests to retrieve a grid from a file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "grid.h"
#include "my.h"

Test(grid_create_from_file, correct_file1)
{
    grid_t grid = NULL;

    grid = grid_create_from_file("maps/my_navy.txt");
    cr_assert_not_null(grid);
    for (unsigned int i = 0 ; i < GRID_SIZE ; i++)
        for (unsigned int j = 0 ; j < GRID_SIZE ; j++)
            cr_assert_eq((cell_is_boat(grid[i][j]) || grid[i][j] == EMPTY), 1);
}

Test(grid_create_from_file, correct_file2)
{
    grid_t grid = NULL;

    grid = grid_create_from_file("maps/my_navy2.txt");
    cr_assert_not_null(grid);
    for (unsigned int i = 0 ; i < GRID_SIZE ; i++)
        for (unsigned int j = 0 ; j < GRID_SIZE ; j++)
            cr_assert_eq((cell_is_boat(grid[i][j]) || grid[i][j] == EMPTY), 1);
}

Test(grid_create_from_file, correct_file3)
{
    grid_t grid = NULL;

    grid = grid_create_from_file("maps/my_navy3.txt");
    cr_assert_not_null(grid);
    for (unsigned int i = 0 ; i < GRID_SIZE ; i++)
        for (unsigned int j = 0 ; j < GRID_SIZE ; j++)
            cr_assert_eq((cell_is_boat(grid[i][j]) || grid[i][j] == EMPTY), 1);
}

Test(grid_create_from_file, bad_fd, .init = cr_redirect_stderr)
{
    grid_t grid = NULL;

    grid = grid_create_from_file("wouloulou dont exist lol this shoudn't work");
    cr_assert_null(grid);
    cr_assert_stderr_eq_str("Couldn't open given file\n");
}

Test(grid_create_from_file, bad_format_in_file, .init = cr_redirect_stderr)
{
    grid_t grid = NULL;

    grid = grid_create_from_file("maps/incorrect_navy.txt");
    cr_assert_null(grid);
    cr_assert_stderr_eq_str("Unexpected line found in file area\n");
}