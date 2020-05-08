/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_label
*/

#include "labels.h"
#include "my.h"

bool is_label(char *str)
{
    register size_t len = my_strlen(str);

    if (!str || !len)
        return (false);
    if (str[len - 1] == LABEL_CHAR)
        return (true);
    return (false);
}

bool is_valid_label(reader_info_t reader_i, char *str)
{
    register size_t len = my_strlen(str);

    if (len > 0 && str[len - 1] == LABEL_CHAR)
        str[len - 1] = 0;
    if (!str || !my_str_is_template(str, LABEL_CHARS)) {
        my_printf("asm, %s, line %d: Invalid label name.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (false);
    }
    return (true);
}