/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_print_grid
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "grid.h"
#include "my.h"

Test(print_grid, empty_grid, .init = cr_redirect_stdout)
{
    grid_t grid = grid_create(8);
    char expected[] =
" |A B C D E F G H\n"
"-+---------------\n"
"1|. . . . . . . .\n"
"2|. . . . . . . .\n"
"3|. . . . . . . .\n"
"4|. . . . . . . .\n"
"5|. . . . . . . .\n"
"6|. . . . . . . .\n"
"7|. . . . . . . .\n"
"8|. . . . . . . .\n";

    grid_print(grid);
    cr_assert_stdout_eq_str(expected);
}

Test(print_grid, pdf_example_1, .init = cr_redirect_stdout)
{
    grid_t grid = grid_create(8);
    char expected[] =
" |A B C D E F G H\n"
"-+---------------\n"
"1|. . 2 . . . . .\n"
"2|. . 2 . . . . .\n"
"3|. . . . . . . .\n"
"4|. . . 3 3 3 . .\n"
"5|. 4 . . . . . .\n"
"6|. 4 . . . . . .\n"
"7|. 4 . 5 5 5 5 5\n"
"8|. 4 . . . . . .\n";

    grid_place_boat(grid, "2:C1:C2");
    grid_place_boat(grid, "3:D4:F4");
    grid_place_boat(grid, "4:B5:B8");
    grid_place_boat(grid, "5:D7:H7");
    grid_print(grid);
    cr_assert_stdout_eq_str(expected);
}