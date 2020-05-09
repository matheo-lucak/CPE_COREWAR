/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_instruction
*/

#include "parser.h"

bool fill_instruction(reader_info_t reader_i, char **parsed_line,
                                                asm_info_t *asm_i)
{
    instruct_t instruct;

    if (!fill_mnemonic(reader_i, &instruct, parsed_line, asm_i))
        return (false);
    if (!fill_params(reader_i, &instruct, parsed_line + 1, asm_i))
        return (false);
    return (ENQUEUE(&(asm_i->instructs), &instruct, instruct_t));
}