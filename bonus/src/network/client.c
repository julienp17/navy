/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXRCVLEN 500
#define PORTNUM 2300

int client_connect(char const *server_address)
{
    char buffer[MAXRCVLEN + 1] = "";
    int len = 0;
    int mysocket = 0;
    struct sockaddr_in dest;

    mysocket = socket(AF_INET, SOCK_STREAM, 0);
    memset(&dest, 0, sizeof(dest));                /* zero the struct */
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK); /* set destination IP number - localhost, 127.0.0.1*/
    dest.sin_port = htons(PORTNUM);                /* set destination port number */
    connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr_in));
    len = recv(mysocket, buffer, MAXRCVLEN, 0);
    /* We have to null terminate the received data ourselves */
    buffer[len] = '\0';
    printf("Sucessfully connected\n", buffer, len);
    close(mysocket);
    return EXIT_SUCCESS;
}