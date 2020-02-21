/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Reset the packet variable and wait for given number of signals
*/

#include <unistd.h>

extern int packet;

void wait_transmission(unsigned int nb_bits)
{
    packet = 0;
    for (unsigned int i = 0 ; i < nb_bits ; i++)
        pause();
}