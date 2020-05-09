/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#include "asm.h"
#include "parser.h"
#include "my.h"

static void init_asm_info(asm_info_t *asm_i)
{
    if (asm_i)
        my_memset((char *)asm_i, 0, sizeof(asm_i));
}

bool asm_core(char *path[])
{
    register size_t index = 0;
    asm_info_t asm_i;
    reader_info_t reader_i;

    if (!path)
        return (false);
    for (; path[index]; index += 1) {
        reader_i = open_file(path[index]);
        if (!parse_file(reader_i, &asm_i))
            return (false);
    }
    if (!link_labels(asm_i.labels, asm_i.instructs))
        return (false);
    return (true);
}