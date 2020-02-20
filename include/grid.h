/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Grid
*/

#ifndef GRID_H_
    #define GRID_H_

    #include <stdbool.h>
    #include "cell_state.h"

    #define GRID_SIZE           8

    typedef cell_t **grid_t;

    grid_t grid_create(unsigned int grid_size);
    void grid_print(grid_t grid);
    int grid_place_boat(grid_t grid, char const *format);
    grid_t get_grid_from_file(char const *filename);
    bool grid_has_boats(grid_t const grid);
#endif