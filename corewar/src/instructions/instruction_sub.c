/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_sub.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_sub(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t values[3] = {0};
    size_t result = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    champion->pc %= MEM_SIZE;
    if (get_instruction_params(vm->memory, &champion->pc,
            &params, i_sub) == 84)
        return 84;
    if (get_ops_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    result = values[0] - values[1];
    if (my_memcpy(&result,
            champion->registers + REG_SIZE * (params.values[2]),
            REG_SIZE) == 84)
        return 84;
    champion->carry = (result == 0) ? true : false;
    return 0;
}