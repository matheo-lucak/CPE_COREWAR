/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_ld.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_ld(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    ssize_t values[2] = {0};
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = increment_pc(champion->pc, 1);
    if (get_instruction_params(vm->memory, &tmp_pc, &params, i_ld) == 84)
        return 84;
    values[0] %= IDX_MOD;
    if (get_ld_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    if (my_memcpy(&values[0],
            champion->registers + REG_SIZE * params.values[1],
            REG_SIZE) == 84)
        return 84;
    champion->carry = (values[0] == 0) ? true : false;
    champion->pc = tmp_pc;
    return 0;
}