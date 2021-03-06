/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** transmission
*/

#ifndef TRANSMISSION_H_
    #define TRANSMISSION_H_

    #include <sys/types.h>

    #define DEFAULT_USLEEP      100000
    #define CONNECTION_USLEEP   10000000
    #define COL_BITMASK         0b00111000
    #define ROW_BITMASK         0b00000111

    typedef struct transmission {
        unsigned int count;
        unsigned char packet;
        pid_t enemy_pid;
    } transmission_t;

    void set_signals_handler(void);
    void send_signal(pid_t pid, int signum);
    void send_coord(char const *coord, pid_t enemy_pid);
    int join_connections(pid_t first_player_pid);
    void wait_transmission(unsigned int nb_bits);
#endif
