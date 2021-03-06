/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** redirect_body
*/

#include "parser.h"
#include "my.h"

bool redirect_body(reader_info_t reader_i, asm_info_t *asm_i)
{
    char parser[4] = {' ', '\t', SEPARATOR_CHAR, 0};
    char **parsed_line = my_str_to_word_array((const char *)reader_i.line,
                                                                parser, 0);
    bool has_label = false;

    if (!parsed_line)
        return (false);
    asm_i->header_info.parsing_core = true;
    if (is_label(parsed_line[0])) {
        has_label = true;
        if (!is_valid_label(reader_i, parsed_line[0]) ||
            !fill_label(reader_i, parsed_line[0], asm_i)) {
            return (false);
        }
    }
    if (parsed_line[has_label] && parsed_line[has_label][0] != '\n' &&
        !fill_instruction(reader_i, parsed_line + has_label, asm_i))
        return (false);
    my_free_arr((void **)parsed_line);
    return (true);
}