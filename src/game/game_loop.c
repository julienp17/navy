/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Loop of the navy game
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "transmission.h"
#include "game_status_enum.h"
#include "my.h"

extern int packet;

static game_status_t player_turn(grid_t enemy_grid, pid_t enemy_pid);
static game_status_t enemy_turn(grid_t player_grid, pid_t enemy_pid);

game_status_t navy_loop(grid_t player_grid, grid_t enemy_grid,
                pid_t enemy_pid, player_t player)
{
    packet = 0;
    if (player == FIRST) {
        if (player_turn(enemy_grid, enemy_pid) != ONGOING)
            return (WON);
        packet = 0;
        if (enemy_turn(player_grid, enemy_pid) != ONGOING)
            return (LOST);
    } else {
        if (enemy_turn(player_grid, enemy_pid) != ONGOING)
            return (LOST);
        packet = 0;
        if (player_turn(enemy_grid, enemy_pid) != ONGOING)
            return (WON);
    }
    print_grids(player_grid, enemy_grid);
    return (ONGOING);
}

static game_status_t player_turn(grid_t enemy_grid, pid_t enemy_pid)
{
    char *coord = NULL;
    int row = 0;
    int col = 0;

    coord = get_input();
    col = coord[0] - 'A';
    row = coord[1] - '0' - 1;
    send_coord(coord, enemy_pid);
    wait_transmission(1);
    enemy_grid[row][col] = (packet) ? HIT : MISS;
    my_putstr(coord);
    my_putstr((enemy_grid[row][col] == HIT) ? ": hit\n\n" : ": missed\n\n");
    free(coord);
    packet = 0;
    wait_transmission(1);
    return ((packet == 1) ? WON : ONGOING);
}

static game_status_t enemy_turn(grid_t player_grid, pid_t enemy_pid)
{
    int row = 0;
    int col = 0;
    bool is_finished = false;

    my_putstr("waiting for enemy's attack...\n");
    wait_transmission(6);
    col = (packet & 0b00111000) >> 3;
    row = packet & 0b00000111;
    player_grid[row][col] = (cell_is_boat(player_grid[row][col])) ? HIT : MISS;
    usleep(100000);
    kill(enemy_pid, (player_grid[row][col] == HIT) ? SIGUSR2 : SIGUSR1);
    my_putchar(col + 'A');
    my_putchar(row + '0' + 1);
    my_putstr((player_grid[row][col] == HIT) ? ": hit\n\n" : ": missed\n\n");
    is_finished = !grid_has_boats(player_grid);
    usleep(100000);
    kill(enemy_pid, (is_finished) ? SIGUSR2 : SIGUSR1);
    return ((is_finished) ? LOST : ONGOING);
}