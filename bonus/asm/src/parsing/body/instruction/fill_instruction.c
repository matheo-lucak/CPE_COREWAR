/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_instruction
*/

#include "parser.h"
#include "my.h"

bool fill_instruction(reader_info_t reader_i, char **parsed_line,
                                                asm_info_t *asm_i)
{
    instruct_t instruct = {0};

    instruct.freer = (void *)&free_instruct;
    if (!fill_mnemonic(reader_i, &instruct, parsed_line, asm_i))
        return (false);
    if (!fill_params(reader_i, &instruct, parsed_line + 1, asm_i))
        return (false);
    instruct.address = asm_i->writing_address;
    instruct.line_nb = reader_i.line_nb;
    instruct.prog_name = my_strdup(reader_i.name);
    asm_i->writing_address += instruct.size;
    return (ENQUEUE(&(asm_i->instructs), &instruct, instruct_t));
}