/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_core.c
*/

#include "core.h"
#include "init.h"

int init_core(core_t *core)
{
    if (!core)
        return 84;
    if (check_opts(core->ac, core->av) == false)
        return 84;
    if (get_nbr_cycle_dump(core->ac, core->av, &core->nbr_cycle_dump) == 84)
        return 84;
    if (get_nbr_programs(core->ac, core->av, &core->nbr_programs) == 84)
        return 84;
    if (get_programs(core->ac, core->av,
            core->nbr_programs, &core->programs) == 84)
        return 84;
    return 0;
}