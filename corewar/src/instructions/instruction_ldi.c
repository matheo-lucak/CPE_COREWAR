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
    size_t values[2] = {0};
    size_t tmp_pc = 0;

    if (!vm || !champion)
        return 84;
    tmp_pc = champion->pc + 1;
    if (get_instruction_params(vm->memory, (int *)&tmp_pc,
            &params, i_ldi) == 84)
        return 84;
    if (get_ops_params_values(&params, vm->memory, champion, values) == 84)
        return 84;
    tmp_pc += (values[0] + values[1]) % IDX_MOD;
    tmp_pc %= MEM_SIZE;
    if (my_memcpy(&values[0], champion->registers +
        REG_SIZE * (params.values[1] - 1), REG_SIZE) == 84)
        return 84;
    champion->pc = tmp_pc;
    champion->carry = true;
    return 0;
}


int main(void)
{
    vm_t vm = {0, 0, 0,
            {0, 144, 1, 0, 0, 0, 2}};
    char registers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    champion_t champion = {registers, 0};

    return instruction_ld(&vm, &champion);
}