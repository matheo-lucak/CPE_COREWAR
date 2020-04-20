/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_loop_in_str_until_c.c
*/

#include <stdbool.h>
#include <stddef.h>

bool my_loop_in_str_until_c(const char *str, const char c, size_t *index)
{
    bool return_value = false;

    if (!str)
        return (false);
    while (str[(*index)] && str[(*index)] != c) {
        return_value = true;
        (*index) += 1;
    }
    return (return_value);
}