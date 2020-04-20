/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_arr_show.c
*/

#include "my.h"

void my_arr_show(char **array)
{
    register size_t index = 0;

    if (!array)
        return;
    while (array[index]) {
        my_printf("%s\n", array[index]);
        index += 1;
    }
}