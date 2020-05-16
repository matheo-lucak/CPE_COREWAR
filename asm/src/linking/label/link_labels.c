/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** link_labels
*/

#include "parser.h"
#include "asm.h"
#include "my.h"

static bool link_one_label(label_t *label, instruct_t *instruct,
                                            parameters_t *param)
{
    int address = -1;

    if (!param || !instruct)
        return (false);
    if (!check_existing_label(label, param->label_name)) {
        my_printf("asm, %s, line %d: Undefined label.\n",
                    instruct->prog_name, instruct->line_nb);
        return (false);
    }
    address = get_label_address(label, param->label_name) - instruct->address;
    if (address == -1)
        return (false);
    if (param->type == T_DIR)
        param->value.dir = address;
    else
        param->value.ind = address;
    return (true);
}

static bool find_linkable_label(label_t *label, instruct_t *instruct)
{
    register size_t index = 0;
    bool success = true;

    for (; index < instruct->param_nb && success; index += 1) {
        if (instruct->params[index].has_label) {
            success = link_one_label(label, instruct,
                            &(instruct->params[index]));
        }
    }
    return (success);
}

bool link_labels(label_t *label, instruct_t *instruct)
{
    if (!label || !instruct)
        return (true);
    for (;instruct; instruct = instruct->next) {
        if (!find_linkable_label(label, instruct))
            return (false);
    }
    return (true);
}