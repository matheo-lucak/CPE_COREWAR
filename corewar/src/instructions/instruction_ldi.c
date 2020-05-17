/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_ldi.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_ldi(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    ssize_t values[2] = {0};
    ssize_t tmp_pc = 0;
    ssize_t index = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = increment_pc(champion->pc, 1);
    if (get_instruction_params(vm->memory, (int *)&tmp_pc,
            &params, i_ldi) == 84 ||
            get_ops_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    index = (champion->pc + (values[0] + values[1]) % IDX_MOD) % MEM_SIZE;
    if (my_memcpy(&vm->memory[index], &index, REG_SIZE) == 84 ||
        my_memcpy(&index, champion->registers +
        REG_SIZE * params.values[2], REG_SIZE) == 84)
        return 84;
    champion->carry = (index == 0) ? true : false;
    champion->pc = tmp_pc;
    return 0;
}