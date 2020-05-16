/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_str_is
*/

#include "my.h"

bool my_str_is_template(const char *str, const char *template)
{
    register size_t index = 0;

    if (!str || !template)
        return (false);
    while (str[index]) {
        if (my_find_char(template, str[index]) == -1)
            return (false);
        index += 1;
    }
    return (true);
}