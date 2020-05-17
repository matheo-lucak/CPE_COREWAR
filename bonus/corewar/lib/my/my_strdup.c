/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup.c
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(src);
    char *dest = NULL;

    if (!src || !(dest = malloc(sizeof(char) * (len + 1))))
        return NULL;
    while (src[j]) {
        dest[i] = src[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
    return dest;
}
