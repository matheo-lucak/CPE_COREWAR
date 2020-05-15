/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_fork.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

int instruction_fork(vm_t *vm, champion_t *champion)
{
    size_t index = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (copy_memory_n_bytes(vm->memory, &tmp_pc, &index, 2) == 84)
        return 84;
    index %= IDX_MOD;
    index += champion->pc;
    index %= MEM_SIZE;
    champion->pc = tmp_pc;
    if (dup_champion(vm, champion, index) == 84)
        return 84;
    return 0;
}