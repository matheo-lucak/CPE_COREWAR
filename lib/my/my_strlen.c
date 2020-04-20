/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strlen.c
*/

#include <unistd.h>

ssize_t my_strlen(const char *str)
{
    ssize_t index = -1;

    if (str)
        while (str[++index]);
    return (index);
}