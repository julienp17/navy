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

extern transmission_t transmission;

static game_status_t player_turn(grid_t enemy_grid);
static game_status_t enemy_turn(grid_t player_grid);

game_status_t navy_loop(grid_t player_grid, grid_t enemy_grid, player_t player)
{
    if (player == FIRST) {
        if (player_turn(enemy_grid) != ONGOING)
            return (WON);
        if (enemy_turn(player_grid) != ONGOING)
            return (LOST);
    } else {
        if (enemy_turn(player_grid) != ONGOING)
            return (LOST);
        if (player_turn(enemy_grid) != ONGOING)
            return (WON);
    }
    print_grids(player_grid, enemy_grid);
    return (ONGOING);
}

static game_status_t player_turn(grid_t enemy_grid)
{
    char *coord = NULL;
    int row = 0;
    int col = 0;

    coord = get_input();
    col = coord[0] - 'A';
    row = coord[1] - '0' - 1;
    send_coord(coord, transmission.enemy_pid);
    wait_transmission(1);
    my_putstr(coord);
    my_putstr((transmission.packet == 1) ? ": hit\n\n" : ": missed\n\n");
    free(coord);
    enemy_grid[row][col] = (transmission.packet || enemy_grid[row][col] == HIT)
                            ? HIT : MISS;
    wait_transmission(1);
    return ((transmission.packet == 1) ? WON : ONGOING);
}

static game_status_t enemy_turn(grid_t player_grid)
{
    int row = 0;
    int col = 0;
    bool is_hit = false;
    bool is_finished = false;

    my_putstr("waiting for enemy's attack...\n");
    wait_transmission(6);
    col = (transmission.packet & COL_BITMASK) >> 3;
    row = (transmission.packet & ROW_BITMASK);
    is_hit = cell_is_boat(player_grid[row][col]);
    send_signal(transmission.enemy_pid, (is_hit) ? SIGUSR2 : SIGUSR1);
    my_putchar(col + 'A');
    my_putchar(row + '0' + 1);
    my_putstr((is_hit) ? ": hit\n\n" : ": missed\n\n");
    player_grid[row][col] = (is_hit || player_grid[row][col] == HIT)?HIT : MISS;
    is_finished = !grid_has_boats(player_grid);
    send_signal(transmission.enemy_pid, (is_finished) ? SIGUSR2 : SIGUSR1);
    return ((is_finished) ? LOST : ONGOING);
}