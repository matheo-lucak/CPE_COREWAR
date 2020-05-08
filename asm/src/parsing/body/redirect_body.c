/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** redirect_body
*/

#include "asm.h"
#include "my.h"

bool redirect_body(reader_info_t reader_i, asm_info_t *asm_i)
{
    char parser[4] = {' ', '\t', SEPARATOR_CHAR, 0};
    char **parsed_line = my_str_to_word_array((const char *)reader_i.line,
                                                                parser, 0);
    if (!parsed_line)
        return (false);
    return (false);
}