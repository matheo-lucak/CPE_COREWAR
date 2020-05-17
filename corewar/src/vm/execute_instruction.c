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
#include "instruction_codes.h"
#include "graphic.h"
#include "update_graphic.h"
#include "my.h"

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

static int execute_instruction(vm_t *vm, champion_t *champion)
{
    instr_code_t code = 0;

    if (!vm || !champion)
        return 84;
    code = (instr_code_t)vm->memory[champion->pc] - 1;
    if (code < 0 || code > 15)
        return 0;
    champion->cycles_left = op_tab[code].nbr_cycles;
    if (instructions[code](vm, champion) == 84)
        return 84;
    return 0;
}

int execute_instructions(vm_t *vm, map_formatter_t *map)
{
    int i = -1;

    while (++i < vm->nbr_champions) {
        if (vm->champions[i].dead == false &&
            vm->champions[i].cycles_left <= 0 &&
            execute_instruction(vm, &vm->champions[i]) == 84)
            return 84;
        if (update_memory_3d(vm, map, &vm->champions[i]) == 84)
            return 84;
        if (my_memcpy(vm->memory, vm->memory_dup, MEM_SIZE) == 84)
            return 84;
        --vm->champions[i].cycles_left;
    }
    return 0;
}