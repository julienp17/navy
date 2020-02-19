/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_print_grid
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cell_state.h"
#include "my.h"

Test(print_grid, empty_grid, .init = cr_redirect_stdout)
{
    grid_t grid = grid_create(8, 8);
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

    print_grid(grid);
    cr_assert_stdout_eq_str(expected);
}