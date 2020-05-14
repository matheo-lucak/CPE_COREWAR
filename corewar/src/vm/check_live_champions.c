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

    if (!vm)
        return 84;
    while (++i < vm->nbr_champions) {
        if (vm->champions[i].last_live >= vm->cycle_to_die) {
            vm->champions[i].dead = true;
            --vm->nbr_live_champions;
        }
    }
    return 0;
}