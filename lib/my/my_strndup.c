/*
** EPITECH PROJECT, 2019
** library
** File description:
** duplicates a string with allocation
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(const char *template, const ssize_t n)
{
    char *dup = NULL;
    ssize_t len_template = my_strnlen(template, n);
    ssize_t count_dup = 0;

    if (len_template == -1)
        return (NULL);
    dup = malloc(sizeof(char) * (len_template + 1));
    if (!dup)
        return (NULL);
    while (template[count_dup] && count_dup < n) {
        dup[count_dup] = template[count_dup];
        count_dup += 1;
    }
    dup[count_dup] = '\0';
    return (dup);
}