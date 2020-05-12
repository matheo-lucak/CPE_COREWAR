/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_lfork.c
*/


#include <stdlib.h>
#include "my.h"
#include "vm.h"
#include "champion.h"

static int dup_champion(vm_t *vm, champion_t *champion, size_t index)
{
    if (!vm || !champion)
        return 84;
    ++vm->nbr_champions;
    if (!(vm->champions = realloc(vm->champions,
            sizeof(champion_t) * (vm->nbr_champions + 1))))
        return 84;
    if (!(vm->champions[vm->nbr_champions - 1].registers =
                  my_cmalloc(REG_SIZE * REG_NUMBER)))
        return 84;
    if (my_memcpy(champion->registers,
            vm->champions[vm->nbr_champions - 1].registers,
            REG_SIZE * REG_NUMBER) == 84)
        return 84;
    vm->champions[vm->nbr_champions - 1].pc = index;
    return 0;
}

int instruction_lfork(vm_t *vm, champion_t *champion)
{
    size_t index = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (my_memcpy(&vm->memory[tmp_pc], &index, 2) == 84)
        return 84;
    index += champion->pc;
    index %= MEM_SIZE;
    if (dup_champion(vm, champion, index) == 84)
        return 84;
    champion->pc = tmp_pc;
    return 0;
}