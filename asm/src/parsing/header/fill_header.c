/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_header
*/

#include <stdlib.h>
#include "header_info.h"
#include "header_error.h"

static char *parse_header_line(reader_info_t reader_i, char *cmd_string)
{
    char *tmp = NULL;

    my_skip_chars(&(reader_i.line), " \t");
    reader_i.line += my_strlen(cmd_string);
    my_skip_chars(&(reader_i.line), " \t");
    tmp = my_quoted_strdup(reader_i.line, '"');
    if (header_parse_error(reader_i.line, reader_i)) {
        return (NULL);
    }
    return (tmp);
}

static bool fill_header_comment(reader_info_t reader_i, header_info_t *header_i)
{
    char *tmp = NULL;
    bool error = true;

    if (header_comment_error(reader_i, header_i))
        return (false);
    tmp = parse_header_line(reader_i, COMMENT_CMD_STRING);
    if (!tmp)
        return (false);
    if (my_strlen(tmp) > PROG_NAME_LENGTH) {
        my_printf("asm, %s, line %d: The program name is too long.\n"
                                            , reader_i.name, reader_i.line_nb);
        error = false;
    }
    my_memcpy(header_i->header.comment, tmp, my_strlen(tmp));
    free(tmp);
    header_i->comment_set = true;
    return (error);
}

static bool fill_header_name(reader_info_t reader_i, header_info_t *header_i)
{
    char *tmp = NULL;
    bool error = true;

    if (header_name_error(reader_i, header_i))
        return (false);
    tmp = parse_header_line(reader_i, NAME_CMD_STRING);
    if (!tmp)
        return (false);
    if (my_strlen(tmp) > COMMENT_LENGTH) {
        my_printf("asm, %s, line %d: The comment is too long.\n"
                                            , reader_i.name, reader_i.line_nb);
        error = false;
    }
    my_memcpy(header_i->header.prog_name, tmp, my_strlen(tmp));
    free(tmp);
    header_i->name_set = true;
    return (error);
}

bool redirect_fill_header(reader_info_t reader_i, header_info_t *header_i)
{
    if (!(reader_i.line) || !header_i)
        return (false);
    if (is_header(reader_i.line, NAME_CMD_STRING))
        return (fill_header_name(reader_i, header_i));
    else if (is_header(reader_i.line, COMMENT_CMD_STRING))
        return (fill_header_comment(reader_i, header_i));
    my_printf("asm, %s, line %d: Invalid instruction.\n",
                                            reader_i.name, reader_i.line_nb);
    return (false);
}