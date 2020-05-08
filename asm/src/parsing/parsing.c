/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing
*/

#include "op.h"
#include "asm.h"
#include "my.h"

static void update_reader(reader_info_t *reader_i)
{
    if (!reader_i)
        return;
    if (reader_i->line) {
        free(reader_i->line);
        reader_i->line_nb += 1;
        reader_i->line = NULL;
    }
    reader_i->line = get_next_line(reader_i->fd);
}

bool parse_file(reader_info_t reader_i, asm_info_t *asm_i)
{

    if (!asm_i || reader_i.fd == -1)
        return (false);
    do {
        update_reader(&reader_i);
        redirect_parsing(reader_i, asm_i);
    } while (reader_i.line);
}