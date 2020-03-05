/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** transmission
*/

#ifndef TRANSMISSION_H_
    #define TRANSMISSION_H_

    #include <sys/types.h>

    #define DEFAULT_USLEEP      1000
    #define MAXRCVLEN           500
    #define PORTNUM             2300

    typedef int socket_t;

    int launch_server(int const port_number);
    char *get_ip_address(void);
    int client_connect(char const *server_address, int const port_number);
#endif
