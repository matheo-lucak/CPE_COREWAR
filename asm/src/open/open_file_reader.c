/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_file_reader
*/

#include <fcntl.h>
#include "open.h"
#include "my.h"

reader_info_t open_file_reader(const char *path)
{
    reader_info_t reader_i = {.fd = -1,
                                .name = NULL,
                                .line = NULL,
                                .line_nb = 1};
    if (!path)
        return (reader_i);
    reader_i.fd = open(path, O_RDONLY);
    reader_i.name = get_file_from_path(path);
    if (reader_i.fd == -1 || !(reader_i.name)) {
        my_putstr("Error in function open: No such file or directory.\n");
    }
    return (reader_i);
}