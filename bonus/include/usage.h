/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Usage for navy
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #define MY_EXIT_SUCCESS         0
    #define MY_EXIT_FAILURE         84
    #define INCORRECT_FILE_MSG      \
    "Can't read given file.\n"
    #define USAGE                   \
    "USAGE\n"                                                                  \
    "     ./navy [first_player_pid] navy_positions\n"                          \
    "DESCRIPTION\n"                                                            \
    "     first_player_pid:  only for the 2nd player."                         \
    "  pid of the first player.\n"                                             \
    "     navy_positions:  file representing the positions of the ships.\n"

    int check_args(int ac, char **av);
#endif
