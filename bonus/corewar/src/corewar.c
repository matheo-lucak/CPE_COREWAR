/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** corewar.c
*/

#include "setup.h"
#include "vm.h"

static int init(setup_t *setup, vm_t *vm)
{
    if (!setup || !vm)
        return 84;
    if (init_setup(setup) == 84)
        return 84;
    if (init_vm(vm, setup) == 84)
        return 84;
    return 0;
}

static int run(vm_t *vm)
{
    if (!vm)
        return 84;
    if (loop(vm) == 84)
        return 84;
    if (get_winner(vm->champions, vm->nbr_champions, vm->last_live) == 84)
        return 84;
    return 0;
}

static int destroy(setup_t *setup, vm_t *vm)
{
    if (!setup || !vm)
        return 84;
    if (destroy_setup(setup) == 84)
        return 84;
    if (destroy_vm(vm) == 84)
        return 84;
    return 0;
}

int corewar(int ac, char **av)
{
    setup_t setup = {0};
    vm_t vm = {0};

    setup.ac = ac;
    setup.av = av;
    if (init(&setup, &vm) == 84)
        return 84;
    if (run(&vm) == 84)
        return 84;
    if (destroy(&setup, &vm) == 84)
        return 84;
    return 0;
}