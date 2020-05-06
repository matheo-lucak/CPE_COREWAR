/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_program_file.c
*/

#include "my.h"
#include "program.h"

static int get_program_magic_number(char *file, int *number)
{
    char dest[4] = {0};

    if (!file)
        return 84;
    if (my_memcpy(file, dest, 4) == 84)
        return 84;
    *number = (int)dest;
    return 0;
}

static int get_program_name(char *file, char *name)
{
    int start = 4;

    if (!file)
        return 84;
    if (my_memcpy(&file[start], name, PROG_NAME_LENGTH) == 84)
        return 84;
    return 0;
}

static int get_program_comment(char *file, char *comment)
{
    int start = 4 + PROG_NAME_LENGTH;

    if (!file)
        return 84;
    if (my_memcpy(&file[start], comment, COMMENT_LENGTH) == 84)
        return 84;
    return 0;
}

static int get_program_instructions(char *file, char **instr, int size)
{
    int start = 4 + PROG_NAME_LENGTH + COMMENT_LENGTH;

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
    if (get_program_magic_number(program->file, &program->header.magic) == 84)
        return 84;
    if (get_program_name(program->file,
            (char *)&program->header.prog_name) == 84)
        return 84;
    if (get_program_comment(program->file,
            (char *)&program->header.comment) == 84)
        return 84;
    if (get_program_instructions(program->file, &program->instructions,
            program->header.prog_size) == 84)
        return 84;
    return 0;
}