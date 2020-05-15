/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_program_file.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"
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

static int read_file(char *path, char **dest)
{
    int fd = open(path, O_RDONLY);
    size_t header_size = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH;
    char buffer[4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH] = {0};
    int instr_size = 0;

    if (fd < 0)
        return 84;
    if (read(fd, buffer, header_size) == -1)
        return 84;
    if (my_memcpy(&buffer[4 + PROG_NAME_LENGTH + 4], &instr_size, 4) == 84)
        return 84;
    if (my_swap_int_endian(&instr_size) == 84)
        return 84;
    if (!(*dest = my_cmalloc(sizeof(char) * (header_size + instr_size))))
        return 84;
    if (my_memcpy(buffer, *dest, header_size) == 84)
        return 84;
    if (read(fd, &(*dest)[header_size], instr_size) == -1)
        return 84;
    return 0;
}

int get_program_file(int ac, char **av, int *index, program_t *program)
{
    if (!av || !index || !program)
        return 84;
    if (*index == ac)
        return 84;
    if (read_file(av[*index], &program->file) == 84)
        return 84;
    return 0;
}