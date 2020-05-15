/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_lfork.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

int instruction_lfork(vm_t *vm, champion_t *champion)
{
    size_t index = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (copy_memory_n_bytes(vm->memory, &tmp_pc, &index, 2) == 84)
        return 84;
    index += champion->pc;
    index %= MEM_SIZE;
    if (dup_champion(vm, champion, index) == 84)
        return 84;
    champion->pc = tmp_pc;
    if (champion->pc < 0)
            champion->pc += MEM_SIZE;
    return 0;
}