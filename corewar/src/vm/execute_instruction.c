/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** execute_instruction.c
*/

#include <stddef.h>
#include "vm.h"
#include "champion.h"
#include "instruction.h"

const instruction_func_t instructions[] = {
        &instruction_live,
        &instruction_ld,
        &instruction_st,
        &instruction_add,
        &instruction_sub,
        &instruction_and,
        &instruction_or,
        &instruction_xor,
        &instruction_zjmp,
        &instruction_ldi,
        &instruction_sti,
        &instruction_fork,
        &instruction_lld,
        &instruction_lldi,
        &instruction_lfork,
        &instruction_aff,
        NULL
};

int execute_instruction(vm_t *vm, champion_t *champion)
{
    int i = -1;
    char code = 0;

    if (!vm || !champion)
        return 84;
    if (champion->cycles_left > 0) {
        --champion->cycles_left;
        return 0;
    }
    code = *champion->pc;
    while (op_tab[++i].mnemonique != 0) {
        if (op_tab[i].code == code &&
            instructions[i](vm, champion) == 84)
            return 84;
    }
    return 0;
}