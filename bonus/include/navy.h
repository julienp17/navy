/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <sys/types.h>
    #include "game.h"

    #define NB_BOATS        4

    int navy(char const *server_address, char const *filename);
    int launch_navy(game_t *game);
    game_status_t navy_loop(game_t *game);

    void print_grids(grid_t player_grid, grid_t enemy_grid);
    char *get_input(void);
#endif