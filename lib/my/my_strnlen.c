/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strlen.c
*/

#include <unistd.h>

ssize_t my_strnlen(const char *str, const ssize_t n)
{
    ssize_t index = -1;

    if (str && n >= 0)
        while (str[++index] && index < n);
    return (index);
}