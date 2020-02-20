/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle the connection between the two players
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "my.h"

static int wait_connection(void);
static int connect(pid_t first_player_pid);
static void confirm_connection(int sig, siginfo_t *info, void *ucontext);

int join_connections(pid_t first_player_pid)
{
    int exit_code = 0;

    if (first_player_pid == 0)
        exit_code = wait_connection();
    else
        exit_code = connect(first_player_pid);
    return (exit_code);
}

static int wait_connection(void)
{
    struct sigaction handle_connection;

    handle_connection.sa_sigaction = confirm_connection;
    handle_connection.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &handle_connection, NULL);
    my_putstr("waiting for enemy connection...\n\n");
    pause();
    my_putstr("enemy connected\n\n");
    return (0);
}

static int connect(pid_t first_player_pid)
{
    struct sigaction handle_connection;

    handle_connection.sa_sigaction = confirm_connection;
    sigaction(SIGUSR1, &handle_connection, NULL);
    if (kill(first_player_pid, SIGUSR2) == -1) {
        my_puterr("error sending signal to first player process\n");
        return (-1);
    }
    pause();
    my_putstr("successfully connected\n\n");
    return (0);
}

static void confirm_connection(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    if (sig == SIGUSR1)
        return;
    if (kill(info->si_pid, SIGUSR1) == -1)
        my_puterr("error sending signal to second player process");
}