/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_zjmp.c
*/

#include "vm.h"
#include "champion.h"

int instruction_zjmp(vm_t *vm, champion_t *champion)
{
    short index = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (copy_memory_n_bytes(vm->memory, &tmp_pc, &index, IND_SIZE) == 84)
        return 84;
    index %= IDX_MOD;
    if (champion->carry == true)
        champion->pc = increment_pc(champion->pc, index);
    return 0;
}