/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests for command line arguments
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "usage.h"

Test(check_args, correct_arguments_first_player)
{
    int ac = 2;
    char *av[] = {"./navy", "maps/my_navy.txt", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_args, correct_arguments_second_player)
{
    int ac = 3;
    char *av[] = {"./navy", "24555", "maps/my_navy2.txt", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_args, negative_pid, .init = cr_redirect_stderr)
{
    int ac = 3;
    char *av[] = {"./navy", "-14", "navy_positions/correct_file1.txt", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_stderr_eq_str(USAGE);
    cr_assert_eq(exit_code, -1);
}

Test(check_args, too_much_arguments, .init = cr_redirect_stderr)
{
    int ac = 4;
    char *av[] = {"./navy", "34566",
                "navy_positions/correct_file1.txt", "plume", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_stderr_eq_str(USAGE);
    cr_assert_eq(exit_code, -1);
}