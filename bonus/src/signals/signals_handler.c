/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Defines the action to take when we receive SIGUSR1 and SIGUSR2
*/

#include <signal.h>
#include "transmission.h"

extern transmission_t transmission;

static void handle_sigusr1(int signum);
static void handle_sigusr2(int signum);

void set_signals_handler(void)
{
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
}

static void handle_sigusr1(int signum)
{
    (void)signum;
    transmission.count++;
    transmission.packet = transmission.packet << 1;
}

static void handle_sigusr2(int signum)
{
    (void)signum;
    transmission.count++;
    transmission.packet = (transmission.packet << 1) + 1;
}