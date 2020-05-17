/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instruction_parameters.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H
#define CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H

#include <sys/types.h>
#include "op.h"
#include "instruction_codes.h"

typedef struct instruction_parameters_s
{
    unsigned char types[MAX_ARGS_NUMBER];
    size_t values[MAX_ARGS_NUMBER];
    size_t read[MAX_ARGS_NUMBER];
} instr_params_t;

int get_instruction_params(char *memory, int *pc,
        instr_params_t *params, instr_code_t code);

int get_ldi_params_values(instr_params_t *params, char *memory,
        champion_t *champion, ssize_t *dest);

int get_logicals_params_values(instr_params_t *params, char *memory,
        champion_t *champion, ssize_t *dest);

#endif //CPE_COREWAR_2019_INSTRUCTION_PARAMETERS_H
