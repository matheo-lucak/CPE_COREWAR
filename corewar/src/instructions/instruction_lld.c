/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_lld.c
*/
#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_lld(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t values[2] = {0};
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (get_instruction_params(vm->memory, &tmp_pc, &params, i_lld) == 84)
        return 84;
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