/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_label
*/

#include "labels.h"

bool free_label(label_t *label)
{
    if (!label)
        return (false);
    if (label->name)
        free(label->name);
    return (true);
}