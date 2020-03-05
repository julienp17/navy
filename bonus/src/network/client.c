/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** Client connect
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "network.h"

static struct sockaddr_in get_socket_address(char const *server_address,
                                            int const port_number);

socket_t client_create(void)
{
    socket_t client_socket = 0;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        return (-1);
    }
    return (client_socket);
}

int client_connect(socket_t client_socket, char const *server_address, int const port_number)
{
    struct sockaddr_in server_socket;

    server_socket = get_socket_address(server_address, port_number);
    if (connect(client_socket, (struct sockaddr *)&server_socket, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static struct sockaddr_in get_socket_address(char const *server_address,
                                            int const port_number)
{
    struct sockaddr_in dest;

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(server_address);
    dest.sin_port = htons(port_number);
    return (dest);
}