/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_arrcpy.c
*/

#include "my.h"

void my_arrcpy(char **dest, char **template)
{
    register size_t index = 0;

    if (!template) {
        dest = NULL;
        return;
    }
    while (template[index]) {
        dest[index] = my_strdup(template[index]);
        index += 1;
    }
}