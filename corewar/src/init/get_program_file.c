/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_program_file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "program.h"

static int copy_line(char *dest, char *line, size_t size)
{
    size_t i = -1;

    if (!dest || !line)
        return 84;
    while (++i < size)
        dest[i] = line[i];
    return 0;
}

static int read_file(char *path, char **dest, int *size)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t read_size = 0;

    if (fd == NULL)
        return 84;
    while (getline(&line, &read_size, fd) > 0) {
        if (!(*dest = realloc(*dest, *size + read_size)))
            return 84;
        if (copy_line(*dest, line, read_size) == 84)
            return 84;
        *size += read_size;
        line = NULL;
    }
    return 0;
}

int get_program_file(int ac, char **av, int *index, program_t *program)
{
    if (!av || !index || !program)
        return 84;
    if (*index == ac)
        return 84;
    if (read_file(av[*index], &program->file, &program->header.prog_size) == 84)
        return 84;
    program->header.prog_size -= 4;
    program->header.prog_size -= PROG_NAME_LENGTH;
    program->header.prog_size -= 8;
    program->header.prog_size -= COMMENT_LENGTH;
    program->header.prog_size -= 4;
    program->header.prog_size -= 1;
    return 0;
}