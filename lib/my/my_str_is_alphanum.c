/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a string only contains alphanumerical characters
*/

#include "my.h"

bool my_str_is_alphanum(const char *str)
{
    register size_t index = 0;

    if (!str || !str[0])
        return (false);
    while (str[index]) {
        if (!my_isalphanum(str[index]))
            return (false);
        index += 1;
    }
    return (true);
}