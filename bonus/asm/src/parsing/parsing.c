/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing
*/

#include "open.h"
#include "parser.h"
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
        if (reader_i.line && !redirect_parsing(reader_i, asm_i))
            return (false);
    } while (reader_i.line);
    return (true);
}

bool parse_all_files(const char *paths[], asm_info_t *asm_i)
{
    register size_t index = 0;
    reader_info_t reader_i = {0};

    for (; paths[index]; index += 1) {
        reader_i = open_file_reader(paths[index]);
        if (!parse_file(reader_i, asm_i))
            return (false);
        if (index == 0 && !is_header_complete(reader_i, asm_i))
            return (false);
        if (reader_i.name)
            free(reader_i.name);
        if (reader_i.fd != -1)
            close(reader_i.fd);
    }
    return (true);
}