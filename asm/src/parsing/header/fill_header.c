/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_header
*/

#include "header_info.h"

static bool fill_header_comment(char *line, header_info_t *header_i)
{

}

static bool fill_header_comment(char *line, header_info_t *header_i)
{

}

bool redirect_fill_header(char *line, header_info_t *header_i)
{
    if (line || !header_i)
        return (false);
    if (is_header(line, COMMENT_CMD_STRING))
        return (fill_header_comment(line, header_i));
    else if (is_header(line, COMMENT_CMD_STRING))
        return (fill_header_comment(line, header_i));
    return (false);
}