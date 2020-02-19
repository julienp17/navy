/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Header file for libmy.a
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdbool.h>

    void my_putchar(char);
    void my_putstr(char const *);
    void my_puterr(char const *);
    void my_free_2d_array(char **arr);

    bool my_is_alpha(char const c);
    bool my_is_num(char const c);
    bool my_str_isalpha(char const *str);
    bool my_str_isnum(char const *str);
    bool my_str_isalphanum(char const *str);

    int my_getnbr(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, unsigned int n);
    int my_strnum_to_int(char *str);
    unsigned int my_strlen(char const *);
    unsigned int my_intlen(int nb);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_count_until_sep(char const *str, char const sep);

    char *my_int_to_strnum(int nb);
    char *my_revstr(char *str);
    char *my_strdupcat(char const *s1, char const *s2);
    char *my_clean_str(char *str);
    char *my_strdup(char const *src);

    char **my_str_to_word_array(char const *str, char const sep);
    char **my_strarr_dup(char **arr);
#endif
