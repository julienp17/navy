/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** wait_transmission
*/

#include <unistd.h>

void wait_transmission(unsigned int nb_bits)
{
    for (unsigned int i = 0 ; i < nb_bits ; i++)
        pause();
}