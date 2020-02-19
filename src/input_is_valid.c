/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Returns true if the player's input is valid, false otherwise
*/

#include <stdbool.h>

bool input_is_valid(char const *input)
{
    return (input[0] >= 'A' && input[0] <= 'H'
            && input[1] >= '1' && input[1] <= '8'
            && input[2] == '\0');
}