/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Returns true if the player's pos is valid, false otherwise
*/

#include <stdbool.h>

bool pos_is_valid(char const *pos)
{
    return (pos[0] >= 'A' && pos[0] <= 'H'
            && pos[1] >= '1' && pos[1] <= '8'
            && pos[2] == '\0');
}