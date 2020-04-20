/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets a string len until meeting a certain char
*/

#include "my.h"

ssize_t my_strlen_until_list_c(const char *str, const char list[])
{
    ssize_t index = -1;

    if (str)
        while (str[++index] && !my_is_char_in_str(list, str[index]));
    return (index);
}