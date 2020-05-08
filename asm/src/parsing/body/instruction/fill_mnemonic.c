/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_mnemonic
*/

#include "parser.h"
#include "my.h"

static ssize_t find_mnemonic(char *mnemonic)
{
    register ssize_t index = 0;

    if (!mnemonic)
        return (-1);
    for (; op_tab[index].mnemonique; index += 1) {
        if (!my_strcmp(op_tab[index].mnemonique, mnemonic))
            return (index);
    }
    return (-1);
}

bool fill_mnemonic(reader_info_t reader_i, instruct_t *instruct,
                            char **parsed_line, asm_info_t *asm_i)
{
    ssize_t index = 0;

    if (!instruct || !parsed_line || !asm_i)
        return (false);
    index = find_mnemonic(parsed_line[0]);
    if (index == -1) {
        my_printf("asm, %s, line %d: Invalid instruction.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (false);
    }
    instruct->code = op_tab[index].code;
    instruct->param_nb = op_tab[index].nbr_args;
    instruct->params_types = op_tab[index].type;
    return (true);
}