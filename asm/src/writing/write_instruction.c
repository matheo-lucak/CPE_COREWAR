/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_instruction
*/

#include "writing.h"

static bool write_instruction_code(int fd, instruct_t *instruct)
{
    ssize_t size = 0;

    size = write(fd, &(instruct->code), sizeof(instruct->code));
    return (size == sizeof(instruct->code) ? true : false);
}

static bool write_param_code(int fd, instruct_t *instruct)
{
    ssize_t size = 0;

    if (!(instruct->param_type_code))
        return (true);
    size = write(fd, &(instruct->param_type_code),
                sizeof(instruct->param_type_code));
    return (size == sizeof(instruct->param_type_code) ? true : false);
}

bool write_instruction(int fd, instruct_t *instruct)
{
    if (!write_instruction_code(fd, instruct))
        return (false);
    if (!write_param_code(fd, instruct))
        return (false);
    if (!write_params(fd, instruct))
        return (false);
    return (true);
}