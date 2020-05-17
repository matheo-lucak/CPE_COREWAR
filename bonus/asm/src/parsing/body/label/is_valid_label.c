/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_valid_label
*/

#include "parser.h"
#include "my.h"

bool is_valid_label(reader_info_t reader_i, char *str)
{
    register size_t len = my_strlen(str);

    if (len > 0 && str[len - 1] == LABEL_CHAR)
        str[len - 1] = 0;
    if (!str || !my_str_is_template(str, LABEL_CHARS)) {
        parsing_error(reader_i, "Invalid label name");
        return (false);
    }
    return (true);
}