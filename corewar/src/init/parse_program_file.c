/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_program_file.c
*/

#include "my.h"
#include "program.h"

static int get_program_mn_size(char *file, int *number, int *size)
{
    int start = 4 + PROG_NAME_LENGTH + 4;

    if (!file)
        return 84;
    if (my_memcpy(file, number, 4) == 84)
        return 84;
    if (my_swap_int_endian(number) == 84)
        return 84;
    if (my_memcpy(&file[start], size, 4) == 84)
        return 84;
    if (my_swap_int_endian(size) == 84)
        return 84;
    return 0;
}

static int get_program_name_comment(char *file, char *name, char *comment)
{
    int start = 4;

    if (!file)
        return 84;
    if (my_memcpy(&file[start], name, PROG_NAME_LENGTH) == 84)
        return 84;
    start += PROG_NAME_LENGTH + 8;
    if (my_memcpy(&file[start], comment, COMMENT_LENGTH) == 84)
        return 84;
    return 0;
}

static int get_program_instructions(char *file, char **instr, int size)
{
    int start = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4;

    if (!file)
        return 84;
    if (!(*instr = my_cmalloc(sizeof(char) * size)))
        return 84;
    if (my_memcpy(&file[start], *instr, size) == 84)
        return 84;
    return 0;
}

int parse_program_file(program_t *program)
{
    if (!program)
        return 84;
    if (get_program_mn_size(program->file,
            &program->header.magic,
            &program->header.prog_size) == 84)
        return 84;
    if (get_program_name_comment(program->file,
            (char *)&program->header.prog_name,
            (char *)&program->header.comment) == 84)
        return 84;
    if (get_program_instructions(program->file, &program->instructions,
            program->header.prog_size) == 84)
        return 84;
    return 0;
}