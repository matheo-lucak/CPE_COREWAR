/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_params
*/

#include "writing.h"
#include "my.h"

static bool write_param(int fd, parameters_t param)
{
    ssize_t size = 0;

    my_rev_memcpy(&(param.value), param.size);
    size = write(fd, &(param.value), param.size);
    return (size == param.size ? true : false);
}

bool write_params(int fd, instruct_t *instruct)
{
    register size_t index = 0;

    for (; index < instruct->param_nb; index += 1) {
        if (!write_param(fd, instruct->params[index]))
            return (false);
    }
    return (true);
}