/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_file
*/

#include <fcntl.h>
#include "parser.h"
#include "my.h"

char *get_file_from_path(char *path)
{
    char **parsed_path = my_str_to_word_array(path, "/", 0);
    int len = my_arrlen(parsed_path);
    char *file_name = NULL;

    if (!len || !parsed_path)
        return (NULL);
    file_name = my_strdup(parsed_path[len - 1]);
    my_free_arr((void **)parsed_path);
    return (file_name);
}

reader_info_t open_file(char *path)
{
    reader_info_t reader_i = {.fd = -1,
                                .name = NULL,
                                .line = NULL,
                                .line_nb = 0};
    if (!path)
        return (reader_i);
    reader_i.fd = open(path, O_RDONLY);
    reader_i.name = get_file_from_path(path);
    if (reader_i.fd == -1 || !(reader_i.name)) {
        my_putstr("Error in function open: No such file or directory.\n");
    }
    return (reader_i);
}