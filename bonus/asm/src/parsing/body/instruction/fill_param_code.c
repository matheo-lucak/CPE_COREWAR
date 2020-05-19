/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_param_code
*/

#include "parser.h"

static const char param_type_template[][2] = {
    {T_REG, 0b01},
    {T_DIR, 0b10},
    {T_IND, 0b11},
    {0, 0b00}
};

static char code_param_type_code(parameters_t param)
{
    size_t index = 0;

    for (; param_type_template[index][0]; index += 1) {
        if (param.type == param_type_template[index][0])
            return (param_type_template[index][1]);
    }
    return (0b00);
}

void fill_param_code(instruct_t *instruct)
{
    byte_parser_t byte = {0};

    if (!instruct)
        return;
    byte.p4 = code_param_type_code(instruct->params[0]);
    byte.p3 = code_param_type_code(instruct->params[1]);
    byte.p2 = code_param_type_code(instruct->params[2]);
    byte.p1 = code_param_type_code(instruct->params[3]);
    instruct->param_type_code = CAST_BYTE_2_CHAR(byte);
}