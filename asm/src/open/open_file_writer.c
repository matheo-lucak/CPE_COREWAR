/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_file_writer
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "asm.h"
#include "open.h"
#include "my.h"

static char *convert_file_name_extension(const char *path)
{
    char *file_name = get_file_from_path(path);
    char *new_file = NULL;
    int dot_pos = my_find_last_char(file_name, '.');

    if (!file_name)
        return (NULL);
    if (dot_pos == -1)
        dot_pos = my_strlen(file_name);
    file_name[dot_pos] = 0;
    new_file = my_strcat(file_name, COR_EXT);
    free(file_name);
    return (new_file);
}

int open_file_writer(const char *path)
{
    char *file = convert_file_name_extension(path);
    int fd = -1;
    int flags =  O_WRONLY | O_CREAT | O_TRUNC;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    if (!file)
        return (-1);
    fd = open(file, flags, mode);
    free(file);
    return (fd);
}