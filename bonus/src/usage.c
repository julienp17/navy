/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Check the command line arguments for navy
*/

#include <stddef.h>
#include <unistd.h>
#include "usage.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        my_puterr(USAGE);
        return (-1);
    }
    if (ac == 3 && !my_str_isnum_pos(av[1])) {
        my_puterr(USAGE);
        return (-1);
    }
    return (0);
}