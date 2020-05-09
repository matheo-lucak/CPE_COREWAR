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
        parsing_error(reader_i, "Syntax error");
    }
    return (error);
}

static inline bool header_name_error(reader_info_t reader_i,
                                        header_info_t *header_i)
{
    if (header_i->name_set) {
        parsing_error(reader_i, "The name can only be defined once");
        return (true);
    }
    if (header_i->parsing_core) {
        parsing_error(reader_i,
                    "The name of your program must be the first line");
        return (true);
    }
    return (false);
}

static inline bool header_comment_error(reader_info_t reader_i,
                                        header_info_t *header_i)
{
    if (!(header_i->name_set)) {
        parsing_error(reader_i, "The comment must be just after the name");
        return (true);
    }
    if (header_i->comment_set) {
        parsing_error(reader_i, "The comment can only be defined once");
        return (true);
    }
    return (false);
}

#endif /* !HEADER_ERROR_H_ */