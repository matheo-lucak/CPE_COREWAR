/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** redirect_params
*/

#include "parser_params.h"
#include "my.h"

static bool fill_label_param(parameters_t *param, char *line)
{
    param->has_label = true;
    param->label_name = my_strdup(line + 1);
    if (!(param->label_name))
        return (false);
    return (true);
}

static bool fill_register_param(reader_info_t reader_i,
                        parameters_t *param, char *line)
{
    if (!(param->types & T_REG)) {
        parsing_error(reader_i,
                        "The argument given to the instruction is invalid");
        return (false);
    }
    if (param_redirect_error(reader_i, line))
        return (false);
    param->value.reg = my_getnbr(line + 1);
    param->size = 1;
    param->type = T_REG;
    param->has_label = false;
    return (true);
}

static bool fill_indirect_param(reader_info_t reader_i,
                        parameters_t *param, char *line)
{
    if (!(param->types & T_IND) ||
        (!param_is_label(line) && !my_str_is(line, my_is_num))) {
        parsing_error(reader_i,
                        "The argument given to the instruction is invalid");
        return (false);
    }
    param->type = T_IND;
    param->size = IND_SIZE;
    if (param_is_label(line))
        return (fill_label_param(param, line));
    param->value.ind = my_getnbr(line);
    param->has_label = false;
    return (true);
}

static bool fill_direct_param(reader_info_t reader_i, char mnemo_code,
                                        parameters_t *param, char *line)
{
    if (!(param->types & T_DIR) ||
        (!param_is_label(line + 1) && !my_str_is(line + 1, my_is_num))) {
        parsing_error(reader_i,
                        "The argument given to the instruction is invalid");
        return (false);
    }
    param->type = T_DIR;
    if ((mnemo_code == 0x0a || mnemo_code == 0x0b || mnemo_code == 0x0e) &&
        (param->types == (T_REG | T_DIR | T_IND) ||
        param->types == (T_DIR | T_REG)))
        param->size = IND_SIZE;
    else
        param->size = DIR_SIZE;
    if (param_is_label(line + 1))
        return (fill_label_param(param, line + 1));
    param->value.dir = my_getnbr(line + 1);
    param->has_label = false;
    return (true);
}

bool redirect_param(reader_info_t reader_i, parameters_t *param,
                                    char mnemo_code, char *line)
{
    if (!line || !param)
        return (false);
    my_memset((char *)param, 0, sizeof(parameters_t));
    if (param_is_direct(line))
        return (fill_direct_param(reader_i, mnemo_code, param, line));
    if (param_is_register(line))
        return (fill_register_param(reader_i, param, line));
    return (fill_indirect_param(reader_i, param, line));
}