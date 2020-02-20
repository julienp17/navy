/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Navy game
*/

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include "usage.h"
#include "grid.h"
#include "navy.h"
#include "transmission.h"
#include "turn.h"

int packet = 0;

int navy(pid_t enemy_pid, char const *filename)
{
    grid_t player_grid = NULL;
    grid_t enemy_grid = NULL;
    turn_t turn = PLAYER;
    int status = 0;

    turn = (enemy_pid == 0) ? PLAYER : ENEMY;
    player_grid = get_grid_from_file(filename);
    enemy_grid = grid_create(GRID_SIZE);
    if (player_grid == NULL || enemy_grid == NULL)
        return (-1);
    enemy_pid = join_connections(enemy_pid);
    if (enemy_pid == -1)
        return (MY_EXIT_FAILURE);
    set_signals_handler();
    while (status == 0) {
        status = navy_loop(player_grid, enemy_grid, enemy_pid, turn);
        turn = (turn == ENEMY) ? PLAYER : ENEMY;
    }
    return (0);
}