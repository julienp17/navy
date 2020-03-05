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
    typedef struct network {
        socket_t server_socket;
        socket_t client_socket;
    } network_t;

    char *get_ip_address(void);

    network_t *network_create(char const *server_address, unsigned int const port_number);

    socket_t server_create(int const port_number);
    socket_t server_accept_connection(socket_t server_socket);
    socket_t client_create(void);
    int client_connect(socket_t client_socket, char const *server_address, int const port_number);
#endif
