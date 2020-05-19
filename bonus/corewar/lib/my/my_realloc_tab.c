/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_realloc_tab.c
*/

#include <stdlib.h>

void *my_cmalloc(size_t size);

void my_memset(void *ptr, size_t size, char set);

void *my_realloc_tab(void *tab, size_t tab_size, size_t dest_size)
{
    size_t i = 0;
    void *dest = NULL;

    if (!dest_size || !(dest = my_cmalloc(dest_size)))
        return NULL;
    if (!tab)
        return dest;
    while (i < tab_size) {
        ((char *)dest)[i] = ((char *)tab)[i];
        ++i;
    }
    free(tab);
    return dest;
}