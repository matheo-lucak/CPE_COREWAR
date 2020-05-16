/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_skip
*/

#include "my.h"

bool my_skip_chars(char **src, char const *template)
{
    register size_t index = 0;

    if (!src || !(*src))
        return (false);
    while ((*src)[0] && my_find_char(template, (*src[0])) != -1) {
        *src += 1;
    }
    return (true);
}

bool my_skip_str(char **src, char *str)
{
    register size_t index = 0;

    if (!src)
        return (false);
    index =  my_hay_needle(*src, str);
    if (index == -1)
        return (false);
    *src += index + my_strlen(str);
    return (true);
}

bool my_skip_is(char **src, bool (*func)(char))
{
    register size_t index = 0;

    if (!src || !func)
        return (false);
    while (*src && func((*src)[0])) {
        *src += 1;
    }
    return (true);
}