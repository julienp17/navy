/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <sys/types.h>

    #define NB_BOATS        4

    int navy(pid_t first_player_pid, char const *filename);
    int join_connections(pid_t first_player_pid);
#endif