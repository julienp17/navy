/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** Server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <string.h>
#include "network.h"
#include "my.h"

static struct sockaddr_in get_server_socket(int const port_number);

socket_t server_create(int const port_number)
{
    struct sockaddr_in serv;
    int opt = 1;
    socket_t server_socket;

    serv = get_server_socket(port_number);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return (-1);
    }
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return (-1);
    }
    if (bind(server_socket, (struct sockaddr *)&serv, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        close(server_socket);
        return (-1);
    }
    return (server_socket);
}

socket_t server_accept_connection(socket_t server_socket)
{
    struct sockaddr_in dest;
    socket_t client_socket = 0;
    socklen_t socksize = sizeof(struct sockaddr_in);

    if (listen(server_socket, 1) == -1) {
        perror("listen");
        return (-1);
    }
    printf("Waiting for connections at : %s...\n", get_ip_address());
    client_socket = accept(server_socket, (struct sockaddr *)&dest, &socksize);
    if (client_socket == -1) {
        perror("accept");
        return (-1);
    }
    printf("Received connection from %s\n\n", inet_ntoa(dest.sin_addr));
    return (client_socket);
}

static struct sockaddr_in get_server_socket(int const port_number)
{
    struct sockaddr_in serv;

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(port_number);
    return (serv);
}