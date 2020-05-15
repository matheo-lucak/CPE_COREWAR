/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_setup.c
*/

#include "my.h"
#include "setup.h"

static int destroy_programs(program_t *programs, int nbr_programs)
{
    int i = -1;

    if (!programs)
        return 84;
    while (++i < nbr_programs)
        my_sfree(programs[i].file);
    return 0;
}

int destroy_setup(setup_t *setup)
{
    if (!setup)
        return 84;
    if (destroy_programs(setup->programs, setup->nbr_programs) == 84)
        return 84;
    my_sfree(setup->programs);
    return 0;
}