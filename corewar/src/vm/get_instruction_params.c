/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_instruction_param.c
*/

#include "op.h"
#include "vm.h"
#include "byte_parser.h"
#include "instruction_codes.h"
#include "instruction_parameters.h"

const int param_sizes[4] =
{
        0,
        1,
        DIR_SIZE,
        IND_SIZE
};

const int tricked_param_sizes[4] =
{
        0,
        1,
        IND_SIZE,
        IND_SIZE
};

static int get_param_types(char *memory, int *pc,
        instr_params_t *params, instr_code_t code)
{
    int i = 0;
    byte_parser_t parser = {0};

    if (!memory || !pc || !params)
        return 84;
    while (i < MAX_ARGS_NUMBER && i < op_tab[code].nbr_args) {
        if (copy_memory_n_bytes(memory, pc, &parser, 1) == 84)
            return 84;
        params->types[i + 3] = parser.p1;
        params->types[i + 2] = parser.p2;
        params->types[i + 1] = parser.p3;
        params->types[i] = parser.p4;
        i += 4;
    }
    return 0;
}

static int get_param_values(char *memory, int *pc,
        instr_params_t *params, instr_code_t code)
{
    int i = -1;

    if (!memory || !pc || !params)
        return 84;
    while (++i < MAX_ARGS_NUMBER && i < op_tab[code].nbr_args) {
        if (copy_memory_n_bytes(memory, pc,
                &params->values[i],
                param_sizes[params->types[i]]) == 84)
            return 84;
    }
    return 0;
}

static int get_tricked_param_values(char *memory, int *pc,
        instr_params_t *params, instr_code_t code)
{
    int i = -1;

    if (!memory || !pc || !params)
        return 84;
    while (++i < MAX_ARGS_NUMBER && i < op_tab[code].nbr_args) {
        if (copy_memory_n_bytes(memory, pc,
                &params->values[i],
                tricked_param_sizes[params->types[i]]) == 84)
            return 84;
    }
    return 0;
}

int get_instruction_params(char *memory, int *pc,
        instr_params_t *params, instr_code_t code)
{
    if (!memory || !pc || !params)
        return 84;
    if (get_param_types(memory, pc, params, code) == 84)
        return 84;
    if (code == i_ldi || code == i_lldi || code == i_sti)
        return get_tricked_param_values(memory, pc, params, code);
    else
        return get_param_values(memory, pc, params, code);
}