/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Reset the packet variable and wait for given number of signals
*/

#include <unistd.h>
#include "transmission.h"

extern transmission_t transmission;

void wait_transmission(unsigned int nb_bits)
{
    transmission.count = 0;
    transmission.packet = 0;
    while (transmission.count != nb_bits);
}