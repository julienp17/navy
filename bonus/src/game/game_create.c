/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** game_create
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"

game_t *game_create(char const *map_filepath, char const *server_address)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (game == NULL) {
        fprintf(stderr, "Couldn't allocate memory for game\n");
        return (NULL);
    }
    game->enemy_grid = grid_create(GRID_SIZE);
    game->player_grid = grid_create_from_file(map_filepath);
    if (game->enemy_grid == NULL || game->player_grid == NULL) {
        fprintf(stderr, "Couldn't create map\n");
        return (NULL);
    }
    game->status = ONGOING;
    game->player_id = (server_address == NULL) ? FIRST : SECOND;
    game->network = network_create(server_address, PORTNUM);
    if (game->network == NULL) {
        fprintf(stderr, "Couldn't set up a network connection\n");
        return (NULL);
    }
    return (game);
}

void game_destroy(game_t *game)
{
    grid_destroy(game->player_grid);
    grid_destroy(game->enemy_grid);
    close(game->network->server_socket);
    close(game->network->client_socket);
    free(game);
}