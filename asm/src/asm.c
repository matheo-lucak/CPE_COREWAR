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

bool asm_core(const char *paths[])
{
    register size_t index = 0;
    asm_info_t asm_i;
    reader_info_t reader_i;

    init_asm_info(&asm_i);
    if (!paths)
        return (false);
    for (; paths[index]; index += 1) {
        reader_i = open_file(paths[index]);
        if (!parse_file(reader_i, &asm_i))
            return (false);
    }
    if (!link_labels(asm_i.labels, asm_i.instructs))
        return (false);
    return (true);
}