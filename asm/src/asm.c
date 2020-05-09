/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#include "asm.h"
#include "open.h"
#include "parser.h"
#include "my.h"

static void update_header(asm_info_t *asm_i)
{
    if (!asm_i)
        return ;
    asm_i->header_info.header.magic = COREWAR_EXEC_MAGIC;
    asm_i->header_info.header.prog_size = get_program_size(asm_i->instructs);
}

bool asm_core(const char *paths[])
{
    register size_t index = 0;
    asm_info_t asm_i = {0};
    reader_info_t reader_i = {0};

    if (!paths)
        return (false);
    for (; paths[index]; index += 1) {
        reader_i = open_file_reader(paths[index]);
        if (!parse_file(reader_i, &asm_i))
            return (false);
    }
    if (!link_labels(asm_i.labels, asm_i.instructs))
        return (false);
    update_header(&asm_i);
    if (!write_file(paths[0], asm_i))
        return (false);
    return (true);
}