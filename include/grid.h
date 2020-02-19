/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Grid
*/

#ifndef GRID_H_
    #define GRID_H_

    #include "cell_state.h"

    #define GRID_SIZE           8

    typedef cell_t **grid_t;

    grid_t grid_create(unsigned int nb_rows, unsigned int nb_cols);
    void grid_print(grid_t grid);
#endif