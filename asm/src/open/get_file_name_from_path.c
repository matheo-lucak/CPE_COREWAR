/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_file_name_from_path
*/

#include "my.h"

char *get_file_from_path(const char *path)
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