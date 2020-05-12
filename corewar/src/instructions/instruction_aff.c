/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_aff.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

int instruction_aff(vm_t *vm, champion_t *champion)
{
    instr_params_t params = {0};
    size_t character = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    if (get_instruction_params(vm->memory, &champion->pc, &params, i_aff) == 84)
        return 84;
    if (my_memcpy(champion->registers + REG_SIZE * params.values[0],
            &character, REG_SIZE) == 84)
        return 84;
    character %= 256;
    if (my_putchar(character) == 84)
        return 84;
    return 0;
}