/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** redirect_parsing
*/

#include "parser.h"
#include "my.h"

bool redirect_parsing(reader_info_t reader_i, asm_info_t *asm_i)
{
    if (is_header(reader_i.line, COMMENT_CMD_STRING) ||
        is_header(reader_i.line, COMMENT_CMD_STRING)) {
        return (redirect_fill_header(reader_i, &(asm_i->header_info)));
    } else {
        return (redirect_body(reader_i, asm_i));
    }
}