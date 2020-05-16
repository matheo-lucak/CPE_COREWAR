/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_vm.c
*/

#include "vm.h"
#include "setup.h"

int init_vm(vm_t *vm, setup_t *setup)
{
    if (!vm || !setup)
        return 84;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->count_live = 0;
    vm->nbr_cycle_dump = setup->nbr_cycle_dump;
    vm->nbr_champions = setup->nbr_programs;
    vm->nbr_live_champions = setup->nbr_programs;
    if (get_champions(&vm->champions, setup->nbr_programs,
            setup->programs) == 84)
        return 84;
    if (get_names(setup->programs, setup->nbr_programs, &(vm->names)) == 84)
        return 84;
    if (write_programs(setup->programs, setup->nbr_programs, vm->memory) == 84)
        return 84;
    return 0;
}