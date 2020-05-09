/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_params
*/

#include "parser_params.h"
#include "my.h"

static bool fill_params_error(reader_info_t reader_i, char **parsed_line,
                                                    instruct_t *instruct)
{
    register int len = my_arrlen(parsed_line);

    if (len > instruct->param_nb) {
        parsing_error(reader_i, "Too many arguments given to the instruction");
        return (false);
    } else if (len < instruct->param_nb) {
        parsing_error(reader_i,
                            "The argument given to the instruction is invalid");
        return (false);
    }
    return (true);
}

static void fill_additionnal_instruct_info(instruct_t *instruct, size_t size)
{
    if (instruct->code == 0x9 ||
        instruct->code == 0xC || instruct->code == 0xF) {
        instruct->params[0].size = IND_SIZE;
        size = IND_SIZE;
    } else if (instruct->code == 0x1) {
        instruct->params[0].size = DIR_SIZE;
        size = DIR_SIZE;
    } else
        size += 1;
    instruct->size = size + 1;
}

bool fill_params(reader_info_t reader_i, instruct_t *instruct,
                        char **parsed_line, asm_info_t *asm_i)
{
    size_t len = my_arrlen(parsed_line);
    size_t index = 0;
    size_t size = 0;

    if (!instruct || !parsed_line || !asm_i)
        return (false);
    if (!fill_params_error(reader_i, parsed_line, instruct))
        return (false);
    for (; index < len; index += 1) {
        if (!redirect_param(reader_i, instruct->params_types[index],
                                        &(instruct->params[index]),
                                        parsed_line[index]))
            return (false);
        size += instruct->params[index].size;
    }
    fill_additionnal_instruct_info(instruct, size);
    return (true);
}