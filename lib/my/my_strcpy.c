/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strcpy.c
*/

#include <stddef.h>

void my_strcpy(char *dest, char *template)
{
    register size_t index = 0;

    if (!template) {
        dest = NULL;
        return;
    }
    while (template[index]) {
        dest[index] = template[index];
        index += 1;
    }
}