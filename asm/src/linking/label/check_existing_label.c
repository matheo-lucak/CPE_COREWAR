/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_existing_label
*/

#include "labels.h"
#include "my.h"

bool check_existing_label(label_t *label, char *label_name)
{
    if (!label_name)
        return (false);
    for (; label; label = label->next) {
        if (!my_strcmp(label->name, label_name))
            return (true);
    }
    return (false);
}