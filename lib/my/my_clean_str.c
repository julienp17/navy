/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Returns the given string without duplicate whitespaces
*/

#include <stdbool.h>

static bool should_copy(char const *str, int i);

char *my_clean_str(char *str)
{
    char *clean_str = str;
    unsigned int j = 0;

    for (unsigned int i = 0 ; str[i] ; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    for (unsigned int i = 0 ; str[i] ; i++) {
        if (should_copy(str, i)) {
            clean_str[j] = str[i];
            j++;
        }
    }
    if (clean_str[j - 1] == ' ' || clean_str[j - 1] == '\t')
        clean_str[j - 1] = '\0';
    clean_str[j] = '\0';
    return (clean_str);
}

static bool should_copy(char const *str, int i)
{
    return !(str[i] == ' '
        && (i == 0
        || str[i - 1] == ' '
        || str[i + 1] == '\0')
    );
}