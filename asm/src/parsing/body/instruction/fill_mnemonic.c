/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_mnemonic
*/

#include "parser.h"
#include "my.h"

static bool fill_mnemonic_error(reader_info_t reader_i, instruct_t *instruct)
{
    if (instruct->code == -1) {
        my_printf("asm, %s, line %d: Invalid instruction.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    return (false);
}

static char find_mnemonic(char *mnemonic)
{
    register size_t index = 0;

    if (!mnemonic)
        return (-1);
    for (; op_tab[index].mnemonique; index += 1) {
        if (!my_strcmp(op_tab[index].mnemonique, mnemonic))
            return (op_tab[index].code);
    }
    return (-1);
}

bool fill_mnemonic(reader_info_t reader_i, instruct_t *instruct,
                            char **parsed_line, asm_info_t *asm_i)
{
    if (!instruct || !parsed_line || !asm_i)
        return (false);
    instruct->code = find_mnemonic(parsed_line[0]);
    if (fill_mnemonic_error(reader_i, instruct))
        return (false);
    return (true);
}