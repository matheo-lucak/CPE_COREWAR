/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** param_is
*/

#include "parser.h"
#include "my.h"

bool param_is_register(char *str)
{
    if (!str || str[0] != 'r')
        return (false);
    return (true);
}

bool param_is_direct(char *str)
{
    if (!str || str[0] != DIRECT_CHAR)
        return (false);
    return (true);
}

bool param_is_label(char *str)
{
    if (!str || str[0] != LABEL_CHAR)
        return (false);
    return (true);
}