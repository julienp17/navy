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
#include "player_enum.h"
#include "game_status_enum.h"
#include "my.h"

transmission_t transmission;

int navy(pid_t enemy_pid, char const *filename)
{
    grid_t player_grid = NULL;
    grid_t enemy_grid = NULL;
    player_t player_id = FIRST;
    game_status_t game_status = ONGOING;

    player_id = (enemy_pid == 0) ? FIRST : SECOND;
    player_grid = grid_create_from_file(filename);
    enemy_grid = grid_create(GRID_SIZE);
    if (player_grid == NULL || enemy_grid == NULL)
        return (-1);
    transmission.enemy_pid = join_connections(enemy_pid);
    if (transmission.enemy_pid == -1)
        return (MY_EXIT_FAILURE);
    set_signals_handler();
    print_grids(player_grid, enemy_grid);
    while (game_status == ONGOING)
        game_status = navy_loop(player_grid, enemy_grid, player_id);
    my_putstr((game_status == WON) ? "I won\n" : "Enemy won\n");
    return (game_status);
}