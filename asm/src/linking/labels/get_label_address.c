/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_label_address
*/

#include "labels.h"
#include "my.h"

int get_label_address(label_t *label, char *label_name)
{
    if (!label_name)
        return (false);
    for (; label; label = label->next) {
        if (!my_strcmp(label->name, label_name))
            return (label->address);
    }
    return (-1);
}