/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup_until.c
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen_until(char const *str, char until);

char *my_strdup_until(char const *src, char until)
{
    int i = 0;
    int len = my_strlen_until(src, until);
    char *dest = NULL;

    if (!src || !(dest = malloc(sizeof(char) * (len + 1))))
        return NULL;
    while (*src && *src != until) {
        dest[i] = *src;
        ++src;
        ++i;
    } dest[i] = '\0';
    return dest;
}
