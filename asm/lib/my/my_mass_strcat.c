/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_mass_strcat
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "my.h"

char *my_mass_strcat(char *src, size_t arg_nb, bool do_free, ...)
{
    register size_t index = 0;
    char *save = src;
    char *argument = NULL;
    va_list ap;

    va_start(ap, do_free);
    for (; src && index < arg_nb; index += 1) {
        argument = va_arg(ap, char *);
        save = src;
        src = my_strcat(src, argument);
        if (do_free && save)
            free(save);
        do_free = true;
    }
    va_end(ap);
    return (src);
}