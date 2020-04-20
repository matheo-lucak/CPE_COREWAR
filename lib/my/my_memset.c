/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_memset.c
*/

#include <unistd.h>

void *my_memset(char *buffer, const char c, size_t nb_bytes)
{
    register size_t index = 0;

    if (!buffer || !nb_bytes)
        return (NULL);
    while (index < nb_bytes) {
        buffer[index] = c;
        index += 1;
    }
    return (buffer);
}