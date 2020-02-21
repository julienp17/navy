/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** send_signal
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "transmission.h"

void send_signal(pid_t pid, int signum)
{
    usleep(DEFAULT_USLEEP);
    kill(pid, signum);
}