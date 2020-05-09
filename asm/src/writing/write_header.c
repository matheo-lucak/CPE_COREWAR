/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_header
*/

#include "open.h"

bool write_header(int fd, header_info_t header_i)
{
    ssize_t len = 0;

    if (fd == -1)
        return (false);
    len = write(fd, &(header_i.header), sizeof(header_t));
    return (len == sizeof(header_t) ? true : false);
}