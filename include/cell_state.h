/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Cell states enumeration
*/

#ifndef CELL_STATE_H_
    #define CELL_STATE_H_

    typedef enum cell_state {
        EMPTY = '.',
        HIT = 'x',
        MISSED = 'o',
    } cell_t;
    typedef cell_t **grid_t;

    grid_t grid_create(unsigned int nb_rows, unsigned int nb_cols);
    void print_grid(grid_t grid);
#endif
