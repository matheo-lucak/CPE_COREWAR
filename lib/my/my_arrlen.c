/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets the size of an array
*/

#include <unistd.h>

ssize_t my_arrlen(char **array)
{
    size_t index = -1;

    if (array)
        while (array[++index]);
    return (index);
}