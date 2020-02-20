/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Cell states enumeration
*/

#ifndef CELL_STATE_H_
    #define CELL_STATE_H_

    #include <stdbool.h>

    typedef enum cell_state {
        EMPTY = '.',
        HIT = 'x',
        MISS = 'o',
    } cell_t;

    bool cell_is_boat(cell_t cell);
#endif
