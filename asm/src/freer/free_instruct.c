/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_instruct
*/

#include "instruction.h"

static bool free_params(instruct_t *instruct)
{
    register size_t index = 0;

    for (; index < instruct->param_nb; index += 1) {
        if (instruct->params[index].has_label &&
            instruct->params[index].label_name) {
            free(instruct->params[index].label_name);
        }
    }
    return (true);
}

    bool free_instruct(instruct_t *instruct)
    {
        if (!instruct)
            return (false);
        if (instruct->prog_name)
            free(instruct->prog_name);
        if (!free_params(instruct))
            return (false);
        return (true);
    }