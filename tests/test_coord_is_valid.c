/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit test to see if a position is valid
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "get_next_line.h"

bool pos_is_valid(char const *input);

Test(pos_is_valid, valid1)
{
    char input[] = "A1";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, true);
}

Test(pos_is_valid, valid2)
{
    char input[] = "H8";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, true);
}

Test(pos_is_valid, valid3)
{
    char input[] = "E6";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, true);
}

Test(pos_is_valid, false_too_long_len)
{
    char input[] = "A1 ";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_lowercase_letter)
{
    char input[] = "a1";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_wrong_letter)
{
    char input[] = "I1";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_not_a_letter)
{
    char input[] = "11";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_empty_letter)
{
    char input[] = " 1";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_empty_number)
{
    char input[] = "A ";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_zero_number)
{
    char input[] = "A0";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}

Test(pos_is_valid, false_wrong_number)
{
    char input[] = "A9";
    bool is_valid = false;

    is_valid = pos_is_valid(input);
    cr_assert_eq(is_valid, false);
}