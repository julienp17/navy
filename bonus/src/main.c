/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Main
*/

#include <stddef.h>
#include <sys/types.h>
#include "usage.h"
#include "my.h"
#include "navy.h"

int main(int ac, char **av)
{
    char *filename = NULL;
    pid_t first_player_pid = 0;
    int exit_code = 0;

    if (check_args(ac, av) == -1)
        return (MY_EXIT_FAILURE);
    filename = (ac == 2) ? av[1] : av[2];
    first_player_pid = (ac == 2) ? 0 : my_strnum_to_int(av[1]);
    exit_code = navy(first_player_pid, filename);
    return (exit_code);
}