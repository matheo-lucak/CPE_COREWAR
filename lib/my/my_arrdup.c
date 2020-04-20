/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** duplicates an array
*/

#include <stdlib.h>
#include "my.h"

char **my_arrdup(const char * const *template)
{
    register size_t index = 0;
    ssize_t size = my_arrlen((char **)template);
    char **dup = NULL;

    if (size == -1)
        return (NULL);
    dup = malloc(sizeof(char *) * (size + 1));
    if (!dup)
        return (NULL);
    while (template[index]) {
        dup[index] = my_strdup(template[index]);
        index += 1;
    }
    dup[size] = NULL;
    return (dup);
}