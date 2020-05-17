/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing_error
*/

#include "parser.h"
#include "my.h"

void parsing_error(reader_info_t reader_i, char *error_msg)
{
    if (error_msg) {
        my_printf("asm, %s, line %d: %s.\n",
                                reader_i.name,
                                reader_i.line_nb,
                                error_msg);
    }
}