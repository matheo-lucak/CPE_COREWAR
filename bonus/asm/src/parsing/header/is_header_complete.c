/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_header_complete
*/

#include "parser.h"

bool is_header_complete(reader_info_t reader_i, asm_info_t *asm_i)
{
    bool completed = true;

    reader_i.line_nb = 1;
    if (!asm_i)
        return (false);
    if (!(asm_i->header_info.name_set)) {
        parsing_error(reader_i, "No name specified");
        completed = false;
    }
    if (!(asm_i->header_info.comment_set)) {
        parsing_error(reader_i, "Warning: No comment specified");
        completed = false;
    }
    return (completed);
}