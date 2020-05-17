/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** my_strndup.c
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const *src, int n)
{
    int i = 0;
    int j = 0;
    int len = (my_strlen(src) < n) ? my_strlen(src) : n;
    char *dest = NULL;

    if (!src || !(dest = malloc(sizeof(char) * (len + 1))))
        return NULL;
    while (src[j] && i < len) {
        dest[i] = src[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
    return dest;
}
