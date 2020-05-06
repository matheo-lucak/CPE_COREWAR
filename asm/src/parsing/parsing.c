/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing
*/

#include "op.h"
#include "asm.h"
#include "my.h"

bool parse_file(int fd, asm_info_t *asm_i)
{
    char *line = NULL;

    if (!asm_i)
        return (false);
    do {
        line = get_next_line(fd);
        if (line)
            free(line);
    } while (line);
}