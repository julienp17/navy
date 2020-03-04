/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Header file for format of a boat line
*/

#ifndef FORMAT_PARSING_H_
    #define FORMAT_PARSING_H_

    #include <stdbool.h>

    #define LINE_LEN            7
    #define SEP                 ':'
    #define NB_SEPS             2

    bool format_is_valid(char const *format);
    bool coord_is_valid(char const *pos);
#endif