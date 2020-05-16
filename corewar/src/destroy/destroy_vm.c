/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_vm.c
*/

#include "my.h"
#include "vm.h"

static int destroy_champions(champion_t *champions, int nbr_champions)
{
    int i = -1;

    if (!champions)
        return 84;
    while (++i < nbr_champions)
        my_sfree(champions[i].registers);
    return 0;
}

static int destroy_names(char **names)
{
    int i = -1;

    if (!names)
        return 84;
    while (names[++i])
        my_sfree(names[i]);
    my_sfree(names);
    return 0;
}

int destroy_vm(vm_t *vm)
{
    if (!vm)
        return 84;
    if (destroy_champions(vm->champions, vm->nbr_champions) == 84)
        return 84;
    if (destroy_names(vm->names) == 84)
        return 84;
    my_sfree(vm->champions);
    return 0;
}