/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** my_memcpy.c
*/

#include <stddef.h>

int my_memcpy(void *src, void *dest, size_t size)
{
    size_t i = -1;

    if (!src || !dest)
        return 84;
    while (++i < size)
        ((char *)dest)[i] = ((char *)src)[i];
    return 0;
}