/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_ops_params_values.c
*/

#include <monetary.h>
#include "my.h"
#include "champion.h"
#include "instruction_parameters.h"

static int get_register_value(void *registers, size_t index, ssize_t *dest)
{
    if (!registers || !dest)
        return 84;
    if (my_memcpy(registers + REG_SIZE * index, dest, REG_SIZE) == 84)
        return 84;
    return 0;
}

static int get_direct_value(size_t param, ssize_t *dest)
{
    if (!dest)
        return 84;
    if (my_memcpy(&param, dest, DIR_SIZE) == 84)
        return 84;
    return 0;
}

static int get_indirect_value(char *memory, int pc, size_t index, ssize_t *dest)
{
    if (!memory || !dest)
        return 84;
    index %= IDX_MOD;
    pc += index;
    pc %= MEM_SIZE;
    if (my_memcpy(&memory[pc], dest, IND_SIZE) == 84)
        return 84;
    return 0;
}

int get_ops_params_values(instr_params_t *params, char *memory,
        champion_t *champion, ssize_t *dest)
{
    int i = -1;

    if (!params || !memory)
        return 84;
    if (!champion || !dest)
        return 84;
    while (params->types[++i] != 0) {
        if (params->types[i] == 1 &&
            get_register_value(champion->registers,
                    params->values[i], &dest[i]) == 84)
            return 84;
        if (params->types[i] == 2 &&
            get_direct_value(params->values[i], &dest[i]) == 84)
            return 84;
        if (params->types[i] == 3 &&
            get_indirect_value(memory, champion->pc,
                    params->values[i], &dest[i]) == 84)
            return 84;
    }
    return 0;
}