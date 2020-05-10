/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_header
*/

#include "open.h"
#include "my.h"

bool write_header(int fd, header_t header)
{
    ssize_t len = 0;

    if (fd == -1)
        return (false);
    my_rev_memcpy(&(header.magic), sizeof(header.magic));
    my_rev_memcpy(&(header.prog_size), sizeof(header.prog_size));
    len = write(fd, &(header), sizeof(header_t));
    return (len == sizeof(header_t) ? true : false);
}