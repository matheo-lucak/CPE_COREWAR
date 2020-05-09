/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_body
*/

#include "open.h"

bool write_body(int fd, instruct_t *instructs)
{
    if (fd == -1)
        return (false);
    for (; instructs; instructs = instructs->next) {
    }
    return (true);
}