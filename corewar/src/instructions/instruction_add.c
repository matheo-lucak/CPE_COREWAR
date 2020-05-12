/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_add.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_add(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t add[2] = {0};
    size_t result = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    if (get_instruction_params(vm->memory, &champion->pc, &params, i_add) == 84)
        return 84;
    if (my_memcpy(champion->registers + REG_SIZE * params.values[0],
            &add[0], REG_SIZE) == 84)
        return 84;
    if (my_memcpy(champion->registers + REG_SIZE * params.values[1],
            &add[1], REG_SIZE) == 84)
        return 84;
    result = add[0] + add[1];
    if (my_memcpy(&result,
            champion->registers + REG_SIZE * params.values[2],
            REG_SIZE) == 84)
        return 84;
    return 0;
}