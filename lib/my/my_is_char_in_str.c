/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** finds a char into a string
*/

#include <stdbool.h>
#include <stddef.h>

bool my_is_char_in_str(const char *str, const char c)
{
    register size_t index = 0;

    if (!str)
        return (false);
    while (str[index]) {
        if (str[index] == c)
            return (true);
        index += 1;
    }
    return (false);
}