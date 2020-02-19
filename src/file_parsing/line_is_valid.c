/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Checks if a line is valid from a navy positions file
*/

#include <stdbool.h>
#include <stddef.h>
#include "my.h"
#include "file_parsing.h"

static bool args_are_valid(char **args, int line_nb);
static bool pos_are_valid(char *first, char *last, int boat_len);

bool line_is_valid(char *line, int line_nb)
{
    char **args = NULL;
    bool is_valid = true;

    if (my_strlen(line) != LINE_LEN || my_count_char(line, SEP) != NB_SEPS)
        return (false);
    args = my_str_to_word_array(line, SEP);
    if (!args_are_valid(args, line_nb))
        is_valid = false;
    my_free_2d_array(args);
    return (is_valid);
}

static bool args_are_valid(char **args, int line_nb)
{
    int boat_len = 0;

    if (!my_is_num(args[0][0]) || args[0][1] != '\0')
        return (false);
    boat_len = FIRST_BOAT_LEN + line_nb;
    if (my_getnbr(args[0]) != boat_len)
        return (false);
    return (pos_are_valid(args[1], args[2], boat_len));
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