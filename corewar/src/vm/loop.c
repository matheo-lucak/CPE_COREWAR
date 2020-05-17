/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** loop.c
*/

#include "vm.h"

static int check_cycle_to_die(int *count_live, int *cycle_to_die)
{
    if (!count_live || !cycle_to_die)
        return 84;
    if (*count_live >= NBR_LIVE) {
        *cycle_to_die -= CYCLE_DELTA;
        *count_live = 0;
    }
    if (*cycle_to_die < 0)
        *cycle_to_die = 0;
    return 0;
}

int loop(vm_t *vm)
{
    int cycle = 0;

    if (!vm)
        return 84;
    while (vm->nbr_live_champions > 0) {
        if (cycle == vm->nbr_cycle_dump &&
            dump_memory(vm->memory) == 84)
            return 84;
        if (cycle == 945)
            cycle = 945;
        if (execute_instructions(vm) == 84)
            return 84;
        if (check_live_champions(vm) == 84)
            return 84;
        if (check_cycle_to_die(&vm->count_live, &vm->cycle_to_die) == 84)
            return 84;
        ++cycle;
    }
    return 0;
}