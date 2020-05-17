/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_free_arr
*/

#include <stdlib.h>
#include "my.h"

void my_free_array(void **array, const int size)
{
    register size_t index = 0;

    if (!array)
        return;
    for (; array[index] && index < size; index += 1) {
        free(array[index]);
    }
    free(array);
}