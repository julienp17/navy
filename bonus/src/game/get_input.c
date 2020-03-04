/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Retrieve the player input
*/

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include "get_next_line.h"
#include "format_parsing.h"
#include "my.h"

static char *input(char const *input_msg);

char *get_input(void)
{
    char *coord = NULL;
    bool is_valid = false;

    while (!is_valid) {
        coord = input("attack: ");
        is_valid = coord_is_valid(coord);
        if (!is_valid)
            my_putstr("wrong position\n");
    }
    return (coord);
}

static char *input(char const *input_msg)
{
    my_putstr(input_msg);
    return (get_next_line(STDIN_FILENO));
}