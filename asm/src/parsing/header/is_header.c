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
    char **parsed_line = my_str_to_word_array(line, " \t", false);

    if (!parsed_line || !cmd_string)
        return (false);
    my_skip_chars(&line, " \t");
    if (parsed_line[0] && !my_strcmp(cmd_string, parsed_line[0])) {
        my_free_arr((void **)parsed_line);
        return (true);
    }
    my_free_arr((void **)parsed_line);
    return (false);
}