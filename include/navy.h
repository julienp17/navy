/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <sys/types.h>
    #include "player_enum.h"
    #include "game_status_enum.h"
    #include "grid.h"

    #define NB_BOATS        4

    int navy(pid_t enemy_pid, char const *filename);
    game_status_t navy_loop(grid_t player_grid, grid_t enemy_grid,
                            pid_t enemy_pid, player_t player);

    void print_grids(grid_t player_grid, grid_t enemy_grid);
    char *get_input(void);
#endif