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
    char *av[] = {"./navy", "navy_positions/correct_file1.txt", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_eq(exit_code, 0);
}

Test(check_args, correct_arguments_second_player)
{
    int ac = 3;
    char *av[] = {"./navy", "24555", "navy_positions/correct_file1.txt", NULL};
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

Test(check_args, invalid_file, .init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"./navy", "unfortunately this file doesn't exist", NULL};
    int exit_code = 0;

    exit_code = check_args(ac, av);
    cr_assert_stderr_eq_str(INCORRECT_FILE_MSG);
    cr_assert_eq(exit_code, -1);
}