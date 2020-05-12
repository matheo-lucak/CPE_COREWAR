/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_live.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

static int reset_live(champion_t *champions, int nbr_champions, int id)
{
    int i = -1;

    if (!champions)
        return 84;
    while (++i < nbr_champions) {
        if (champions[i].id == id)
            champions[i].last_live = 0;
    }
    return 0;
}

int instruction_live(vm_t *vm, champion_t *champion)
{
    int id = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    if (my_memcpy(&vm->memory[champion->pc], &id, 4) == 84)
        return 84;
    if (reset_live(vm->champions, vm->nbr_champions, id) == 84)
        return 84;
    return 0;
}