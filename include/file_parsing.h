/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** file_parsing
*/

#ifndef FILE_PARSING_H_
    #define FILE_PARSING_H_

    #include <stdbool.h>

    #define LINE_LEN            7
    #define SEP                 ':'
    #define NB_SEPS             2
    #define FIRST_BOAT_LEN      2

    bool line_is_valid(char *line, int line_nb);
#endif