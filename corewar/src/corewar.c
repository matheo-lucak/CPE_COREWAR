/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** corewar.c
*/

#include "setup.h"
#include "vm.h"

int corewar(int ac, char **av)
{
    setup_t setup = {0};
    vm_t vm = {0};

    setup.ac = ac;
    setup.av = av;
    if (init_setup(&setup) == 84)
        return 84;
    if (init_vm(&vm, &setup) == 84)
        return 84;
    if (loop(&vm) == 84)
        return 84;
    if (get_winner(vm.champions, vm.nbr_champions, vm.last_live) == 84)
        return 84;
    return 0;
}