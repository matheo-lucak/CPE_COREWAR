/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_xor.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_xor(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t values[3] = {0};
    size_t result = 0;
    int tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    tmp_pc %= MEM_SIZE;
    if (get_instruction_params(vm->memory, &tmp_pc, &params, i_and) == 84 ||
        get_ops_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    result = values[0] ^ values[1];
    if (my_memcpy(&result,
            champion->registers + REG_SIZE * params.values[2], REG_SIZE) == 84)
        return 84;
    if (result == 0)
        champion->carry = true;
    champion->pc = tmp_pc;
    return 0;
}