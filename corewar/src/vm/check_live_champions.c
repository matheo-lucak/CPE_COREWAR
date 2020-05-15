/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** check_live_champions.c
*/

#include "vm.h"
#include "champion.h"

int check_live_champions(vm_t *vm)
{
    int i = -1;
    int count_live = 0;

    if (!vm)
        return 84;
    while (++i < vm->nbr_champions) {
        ++vm->champions[i].last_live;
        if (vm->champions[i].last_live >= vm->cycle_to_die)
            vm->champions[i].dead = true;
        if (vm->champions[i].dead == false)
            ++count_live;
    }
    vm->nbr_live_champions = count_live;
    return 0;
}