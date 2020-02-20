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
#include "navy.h"

extern int packet;

static pid_t wait_connection(void);
static pid_t connect(pid_t first_player_pid);
static void confirm_connection(int sig, siginfo_t *info, void *ucontext);

int join_connections(pid_t enemy_pid)
{
    my_putstr("my_pid: ");
    my_putstr(my_int_to_strnum(getpid()));
    my_putchar('\n');
    if (enemy_pid == 0)
        enemy_pid = wait_connection();
    else
        enemy_pid = connect(enemy_pid);
    return (enemy_pid);
}

static pid_t wait_connection(void)
{
    struct sigaction handle_connection;

    handle_connection.sa_sigaction = confirm_connection;
    handle_connection.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &handle_connection, NULL);
    my_putstr("waiting for enemy connection...\n\n");
    pause();
    my_putstr("enemy connected\n\n");
    return (packet);
}

static pid_t connect(pid_t const enemy_pid)
{
    struct sigaction handle_connection;

    handle_connection.sa_sigaction = confirm_connection;
    sigaction(SIGUSR1, &handle_connection, NULL);
    if (kill(enemy_pid, SIGUSR2) == -1) {
        my_puterr("error sending signal to first player process\n");
        return (-1);
    }
    pause();
    my_putstr("successfully connected\n\n");
    return (enemy_pid);
}

static void confirm_connection(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    if (sig == SIGUSR1)
        return;
    packet = info->si_pid;
    if (kill(info->si_pid, SIGUSR1) == -1)
        my_puterr("error sending signal to second player process");
}