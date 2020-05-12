/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_st.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

static int write_value(vm_t *vm, champion_t *champion, size_t *values,
        instr_params_t params)
{
    size_t index = 0;

    if (!vm || !champion || !values)
        return 84;
    if (params.types[1] == 1) {
        if (my_memcpy(&values[0], champion->registers +
                                  REG_SIZE * (params.values[1] - 1), REG_SIZE) == 84)
            return 84;
    } else {
        index = (values[1] % IDX_MOD + champion->pc) % MEM_SIZE;
        if (write_memory_n_bytes(vm->memory, (int *)&index,
                &values[0], REG_SIZE) == 84)
            return 84;
    }
    return 0;
}

int instruction_st(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t values[2] = {0};
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    if (get_instruction_params(vm->memory, &tmp_pc, &params, i_st) == 84 ||
        get_ops_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    if (write_value(vm, champion, values, params) == 84)
        return 84;
    champion->pc = tmp_pc;
    return 0;
}