/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_memset.c
*/

#include <stddef.h>

void my_memset(void *ptr, size_t size, char set)
{
    size_t i = 0;
    char *tmp = ptr;

    while (i < size) {
        tmp[i] = set;
        ++i;
    }
}
