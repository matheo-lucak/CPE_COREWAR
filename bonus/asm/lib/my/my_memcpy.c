/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_memcpy
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    size_t index = 0;

    if (!dest || !src)
        return (NULL);
    while (index < n) {
        *((char *)dest + index) = *((char *)src + index);
        index++;
    }
    return (dest);
}

void *my_rev_memcpy(void *src, size_t n)
{
    char buf[n];
    size_t index = 0;

    if (!src)
        return (NULL);
    if (n <= 1)
        return (src);
    my_memcpy(buf, src, n);
    while (index < n) {
        *((char *)src + index) = *((char *)buf + n - index - 1);
        index++;
    }
    return (src);
}