/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** check_args.c
*/

#include <stdbool.h>
#include "my.h"

static bool check_opt(char *arg)
{
    if (!arg)
        return false;
    if (my_strcmp(arg, "-dump") &&
        my_strcmp(arg, "-n") &&
        my_strcmp(arg, "-a"))
        return false;
    return true;
}

bool check_opts(int ac, char **av)
{
    int i = 0;

    if (!av)
        return false;
    while (++i < ac) {
        if (av[i][0] == '-' && check_opt(av[i]) == false)
            return false;
    }
    return true;
}