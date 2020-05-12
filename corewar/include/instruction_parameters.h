/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instruction_parameters.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H
#define CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H

#include <stddef.h>
#include "op.h"
#include "instruction_codes.h"

typedef struct instruction_parameters_s
{
    char types[MAX_ARGS_NUMBER];
    size_t values[MAX_ARGS_NUMBER];
} instr_params_t;

int get_instruction_params(char *memory, int *pc,
        instr_params_t *params, instr_code_t code);

int get_params_values(instr_params_t *params, char *memory,
        champion_t *champion, size_t *dest);

#endif //CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H
