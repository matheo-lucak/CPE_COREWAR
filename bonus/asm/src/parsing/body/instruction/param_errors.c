/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** param_errors
*/

#include "parser.h"
#include "my.h"

bool param_redirect_error(reader_info_t reader_i, char *line)
{
    int reg_nb = 0;

    if (!line)
        return (true);
    reg_nb = my_getnbr(line + 1);
    if (reg_nb > REG_NUMBER || reg_nb <= 0 ||
        !my_str_is(line + 1, my_is_num)) {
        parsing_error(reader_i, "Invalid register number");
        return (true);
    }
    return (false);
}