/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** writing
*/

#include "open.h"
#include "writing.h"

bool write_file(const char *path, asm_info_t asm_i)
{
    int fd = open_file_writer(path);

    if (fd == -1)
        return (false);
    if (!write_header(fd, asm_i.header_info))
        return (false);
    if (!write_body(fd, asm_i.instructs))
        return (false);
    close(fd);
    return (true);
}