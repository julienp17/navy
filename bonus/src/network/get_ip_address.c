/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** Return the wifi ip address of the machine
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <ifaddrs.h>

char *get_ip_address(void)
{
    struct ifaddrs *ifaddr, *ifa;
    int family = 0;
    int exit_code = 0;
    char *ip_address = NULL;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return (NULL);
    }
    for (ifa = ifaddr ; ifa != NULL ; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;
        family = ifa->ifa_addr->sa_family;
        if (family != AF_INET || strcmp(ifa->ifa_name, "wlp2s0") != 0)
            continue;
        ip_address = malloc(sizeof(char) * 20);
        if (ip_address == NULL) {
            perror("malloc");
            return (NULL);
        }
        exit_code = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                        ip_address, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
        if (exit_code != 0) {
            fprintf(stderr, "getnameinfo() failed: %s\n", gai_strerror(exit_code));
            return (NULL);
        }
    }
    freeifaddrs(ifaddr);
    return (ip_address);
}