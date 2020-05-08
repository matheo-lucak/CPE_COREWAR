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