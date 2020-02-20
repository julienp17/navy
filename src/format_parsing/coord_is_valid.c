/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Returns true if the player's coord is valid, false otherwise
*/

#include <stdbool.h>

bool coord_is_valid(char const *coord)
{
    return (coord
            && coord[0] >= 'A' && coord[0] <= 'H'
            && coord[1] >= '1' && coord[1] <= '8'
            && coord[2] == '\0');
}