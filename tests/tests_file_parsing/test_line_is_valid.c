/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Unit tests to check if a file is valid for navy positions
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>
#include "file_parsing.h"
#include "get_next_line.h"

Test(line_is_valid, incorrect_first_lines)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("incorrect_file.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    line = get_next_line(fd);
    while (line) {
        is_valid = line_is_valid(line, 0);
        cr_assert_eq(is_valid, false);
        line = get_next_line(fd);
    }
}

Test(line_is_valid, correct_file1)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("tests/tests_file_parsing/correct_file1.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    for (int i = 0 ; i < 4 ; i++) {
        line = get_next_line(fd);
        is_valid = line_is_valid(line, i);
        cr_assert_eq(is_valid, true);
    }
}

Test(line_is_valid, correct_file2)
{
    int fd = 0;
    char *line = NULL;
    bool is_valid = false;

    fd = open("tests/tests_file_parsing/correct_file2.txt", O_RDONLY);
    if (fd < 0)
        close(fd);
    for (int i = 0 ; i < 4 ; i++) {
        line = get_next_line(fd);
        is_valid = line_is_valid(line, i);
        cr_assert_eq(is_valid, true);
    }
}