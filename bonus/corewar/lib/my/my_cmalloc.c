/*
** EPITECH PROJECT, 2019
** mul_my_runner_2019
** File description:
** my_cmalloc.c
*/

#include <stdlib.h>

void my_memset(void *ptr, size_t size, char set);

void *my_cmalloc(size_t size)
{
    void *dest = malloc(size);

    if (!dest)
        return NULL;
    my_memset(dest, size, 0);
    return dest;
}