/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Checks if a format is valid
*/

#include <stdbool.h>
#include <stddef.h>
#include "my.h"
#include "format_parsing.h"

static bool args_are_valid(char **args);
static bool pos_are_valid(char *first, char *last, int boat_len);

bool format_is_valid(char const *format)
{
    char **args = NULL;
    bool is_valid = true;

    if (format == NULL || format[0] == 0)
        return (false);
    if (my_strlen(format) != LINE_LEN || my_count_char(format, SEP) != NB_SEPS)
        return (false);
    args = my_str_to_word_array(format, SEP);
    if (!args_are_valid(args))
        is_valid = false;
    my_free_2d_array(args);
    return (is_valid);
}

static bool args_are_valid(char **args)
{
    char *boat_len = args[0];
    char *first_pos = args[1];
    char *last_pos = args[2];

    if (boat_len[0] < '1' || boat_len[0] > '9' || boat_len[1] != '\0')
        return (false);
    return (pos_are_valid(first_pos, last_pos, boat_len[0] - '0'));
}

static bool pos_are_valid(char *first, char *last, int boat_len)
{
    if (my_strlen(first) != 2 || my_strlen(last) != 2)
        return (false);
    if (!my_is_alpha_upper(first[0]) || !my_is_alpha_upper(last[0]))
        return (false);
    if (!my_is_num(first[1]) || !my_is_num(last[1]))
        return (false);
    if (my_strcmp(first, last) == 0)
        return (false);
    if (first[0] != last[0] && first[1] != last[1])
        return (false);
    if (first[0] == last[0])
        return (last[1] - first[1] + 1 == boat_len);
    return (last[0] - first[0] + 1 == boat_len);
}