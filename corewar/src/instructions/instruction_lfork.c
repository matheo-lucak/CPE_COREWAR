/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_lfork.c
*/

#include "vm.h"
#include "champion.h"

int instruction_lfork(vm_t *vm, champion_t *champion)
{
    ssize_t index = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = increment_pc(champion->pc, 1);
    if (copy_memory_n_bytes(vm->memory, &tmp_pc, &index, 2) == 84)
        return 84;
    index = increment_pc(index, champion->pc);
    champion->pc = tmp_pc;
    if (dup_champion(vm, champion, index) == 84)
        return 84;
    return 0;
}