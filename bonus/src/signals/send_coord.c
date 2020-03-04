/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Translate a coordinate to signals and vice-versa
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

static char *decimal_to_binary(int decimal);

void send_coord(char const *coord, pid_t enemy_pid)
{
    char *letter_binary = NULL;
    char *number_binary = NULL;

    letter_binary = decimal_to_binary(coord[0] - 1);
    number_binary = decimal_to_binary(coord[1] - 1);
    for (unsigned int i = 0 ; i < 3 ; i++) {
        kill(enemy_pid, (letter_binary[i] - '0' == 0) ? SIGUSR1 : SIGUSR2);
        usleep(10000);
    }
    for (unsigned int i = 0 ; i < 3 ; i++) {
        kill(enemy_pid, (number_binary[i] - '0' == 0) ? SIGUSR1 : SIGUSR2);
        usleep(10000);
    }
    free(letter_binary);
    free(number_binary);
}

static char *decimal_to_binary(int decimal)
{
    char *binary = NULL;

    binary = malloc(sizeof(char) * 4);
    for (unsigned int i = 0 ; decimal > 0 ; i++) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[3] = '\0';
    return (my_revstr(binary));
}