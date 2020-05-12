/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_zjmp.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

int instruction_zjmp(vm_t *vm, champion_t *champion)
{
    short index = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    if (my_memcpy(&vm->memory[champion->pc], &index, 2) == 84)
        return 84;
    index %= IDX_MOD;
    if (champion->carry == true) {
        champion->pc += index;
        champion->pc %= MEM_SIZE;
    }
    return 0;
}