/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** Game structure
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "grid.h"
    #include "player_enum.h"
    #include "game_status_enum.h"
    #include "network.h"

    typedef struct game {
        grid_t player_grid;
        grid_t enemy_grid;
        player_t player_id;
        game_status_t status;
        network_t *network;
    } game_t;

    game_t *game_create(char const *map_filepath, char const *server_address);
    void game_destroy(game_t *game);
#endif
