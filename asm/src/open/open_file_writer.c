/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_file_writer
*/

#include <fcntl.h>
#include "asm.h"
#include "open.h"
#include "my.h"

static char *convert_file_name_extension(const char *path)
{
    char *file_name = get_file_from_path(path);
    char *new_file = NULL;
    int dot_pos = my_find_last_char(path, '.');

    if (!file_name)
        return (NULL);
    if (dot_pos == -1)
        dot_pos = my_strlen(path);
    file_name[dot_pos] = 0;
    new_file = my_strcat(file_name, COR_EXT);
    free(file_name);
    return (new_file);
}

int open_file_writer(const char *path)
{
    char *file = convert_file_name_extension(path);
    int fd = -1;

    if (!file)
        return (-1);
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC);
    free(file);
    return (fd);
}