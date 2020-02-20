/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests to check if a file is valid for navy positions
*/

#include <stdio.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>
#include "format_parsing.h"
#include "get_next_line.h"

Test(format_is_valid, null_string)
{
    char *line = NULL;
    bool is_valid = false;

    is_valid = format_is_valid(line);
    cr_assert_eq(is_valid, false);
}

Test(format_is_valid, empty_string)
{
    char *line = "";
    bool is_valid = false;

    is_valid = format_is_valid(line);
    cr_assert_eq(is_valid, false);
}

Test(format_is_valid, incorrect_first_lines)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("maps/incorrect_navy.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    line = get_next_line(fd);
    while (line) {
        is_valid = format_is_valid(line);
        cr_assert_eq(is_valid, false);
        line = get_next_line(fd);
    }
}

Test(format_is_valid, correct_file1)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("maps/my_navy.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    for (int i = 0 ; i < 4 ; i++) {
        line = get_next_line(fd);
        is_valid = format_is_valid(line);
        cr_assert_eq(is_valid, true);
    }
}

Test(format_is_valid, correct_file2)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("maps/my_navy2.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    for (int i = 0 ; i < 4 ; i++) {
        line = get_next_line(fd);
        is_valid = format_is_valid(line);
        cr_assert_eq(is_valid, true);
    }
}