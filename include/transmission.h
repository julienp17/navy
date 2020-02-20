/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** transmission
*/

#ifndef TRANSMISSION_H_
    #define TRANSMISSION_H_

    #include <sys/types.h>

    void set_signals_handler(void);
    void send_coord(char const *coord, pid_t enemy_pid);
    int join_connections(pid_t first_player_pid);
    void wait_transmission(unsigned int nb_bits);
#endif