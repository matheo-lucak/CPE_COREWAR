/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** header_error
*/

#ifndef HEADER_ERROR_H_
#define HEADER_ERROR_H_

#include "parser.h"
#include "header_info.h"
#include "my.h"

static inline bool header_parse_error(char *line,
                                        reader_info_t reader_i)
{
    bool error = false;
    int scnd_quote_index = 0;

    if (!line || my_count_char(line, '"')  != 2 || line[0] != '"')
        error = true;
    scnd_quote_index = my_find_char(line + 1, '"');
    if (scnd_quote_index == -1)
        error = true;
    line += scnd_quote_index + 1;
    if (line[0] != '"')
        error = true;
    my_skip_chars(&line, " \"\t");
    if (line[0])
        error = true;
    if (error) {
        my_printf("asm, %s, line %d: Syntax error.\n"
                                            , reader_i.name, reader_i.line_nb);
    }
    return (error);
}

static inline bool header_name_error(reader_info_t reader_i,
                                        header_info_t *header_i)
{
    if (header_i->name_set) {
        my_printf("asm, %s, line %d: The name can only be defined once.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    if (header_i->parsing_core) {
        my_printf("asm, %s, line %d: The name of your program must be"
                                                    "the first line.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    return (false);
}

static inline bool header_comment_error(reader_info_t reader_i,
                                        header_info_t *header_i)
{
    if (!(header_i->name_set)) {
        my_printf("asm, %s, line %d: The comment must be just after the name.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    if (header_i->comment_set) {
        my_printf("asm, %s, line %d: The comment can only be defined once.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    return (false);
}

#endif /* !HEADER_ERROR_H_ */