/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_nb_char_in_str.c
*/

#include <stddef.h>

size_t my_nb_char_in_str(const char *str, const char c)
{
    register size_t index = 0;
    size_t nb = 0;

    if (!str)
        return (0);
    if (c == '\0')
        return (1);
    while (str[index]) {
        if (str[index] == c)
            nb += 1;
        index += 1;
    }
    return (nb);
}