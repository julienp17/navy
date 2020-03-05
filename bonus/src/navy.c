/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Navy game
*/

#include <stddef.h>
#include "game.h"
#include "my.h"
#include "navy.h"

int navy(char const *server_address, char const *filename)
{
    int exit_code = 0;
    game_t *game = NULL;

    game = game_create(filename, server_address);
    if (game == NULL)
        return (-1);
    exit_code = launch_navy(game);
    game_destroy(game);
    return (exit_code);
}

int launch_navy(game_t *game)
{
    print_grids(game->player_grid, game->enemy_grid);
    while (game->status == ONGOING)
        game->status = navy_loop(game);
    my_putstr((game->status == WON) ? "I won\n" :
            (game->status == LOST) ? "Enemy won\n" :
            (game->status == NETWORK_ERROR) ? "Connection lost\n":
            "Unknown error occured\n");
    return (game->status);
}