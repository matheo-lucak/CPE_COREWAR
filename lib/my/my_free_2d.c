/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** frees an array
*/

#include <stdlib.h>

void my_free_2d(void **array)
{
    register size_t index = 0;

    if (!array)
        return;
    while (array[index]) {
        free(array[index]);
        index += 1;
    }
    free(array);
}