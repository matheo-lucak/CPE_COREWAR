/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_body
*/

#include "writing.h"

bool write_body(int fd, instruct_t *instructs)
{
    if (fd == -1)
        return (false);
    for (; instructs; instructs = instructs->next) {
        if (!instructs)
            continue;
        if (!write_instruction(fd, instructs))
            return (false);
    }
    return (true);
}