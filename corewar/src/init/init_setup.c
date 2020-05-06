/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_setup.c
*/

#include "setup.h"

int init_setup(setup_t *setup)
{
    if (!setup)
        return 84;
    if (check_opts(setup->ac, setup->av) == false)
        return 84;
    if (get_nbr_cycle_dump(setup->ac, setup->av, &setup->nbr_cycle_dump) == 84)
        return 84;
    if (get_nbr_programs(setup->ac, setup->av, &setup->nbr_programs) == 84)
        return 84;
    if (get_programs(setup->ac, setup->av,
            setup->nbr_programs, &setup->programs) == 84)
        return 84;
    return 0;
}