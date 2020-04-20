/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_arrcmp.c
*/

#include "my.h"

bool my_arr_eq_arr(char **first, char **second)
{
    register size_t index = 0;

    if (!first || !second)
        return (!first && !second) ? true : false;
    while (first[index] && second[index]) {
        if (!my_str_eq_str(first[index], second[index]))
            return (false);
        index += 1;
    }
    return (first[index] == second[index]) ? true : false;
}