/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** network
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "network.h"
#include "player_enum.h"


network_t *network_create(char const *server_address, unsigned int const port_number)
{
    network_t *network = NULL;

    network = malloc(sizeof(network));
    if (network == NULL) {
        fprintf(stderr, "Couldn't allocate memory for network\n");
        return (NULL);
    }
    if (server_address == NULL) {
        network->server_socket = server_create(port_number);
        network->client_socket = server_accept_connection(network->server_socket);
    } else {
        network->server_socket = 0;
        network->client_socket = client_create();
        if (client_connect(network->client_socket, server_address, port_number) == EXIT_FAILURE) {
            fprintf(stderr, "Couldn't connect to server\n");
            return (NULL);
        }
    }
    return (network);
}