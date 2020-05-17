/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** my_strconcat.c
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strconcat(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(s1) + my_strlen(s2);
    char *dest = NULL;

    if ((!s1 && !s2) || !(dest = malloc(sizeof(char) * (len + 1))))
        return NULL;
    while (s1 && s1[i]) {
        dest[i] = s1[i];
        ++i;
    }
    while (s2 && s2[j]) {
        dest[i] = s2[j];
        ++i;
        ++j;
    }
    dest[i] = 0;
    return dest;
}
