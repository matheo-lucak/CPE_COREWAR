/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_header
*/

#include "header_info.h"
#include "my.h"

bool is_header(char *line, char *cmd_string)
{
    register int len = 0;

    if (!line || !cmd_string)
        return (false);
    len = my_strlen(cmd_string);
    my_skip_chars(&line, " \t");
    if (!my_strncmp(line, cmd_string, len) &&
        (line[len] == ' ' || line[len] == '\t')) {
        return (true);
    }
    return (false);
}