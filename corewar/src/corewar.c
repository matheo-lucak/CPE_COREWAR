/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** corewar.c
*/

#include "core.h"
#include "init.h"

int corewar(int ac, char **av)
{
    core_t core = {ac, av};

    if (init_core(&core) == 84)
        return 84;
    return 0;
}