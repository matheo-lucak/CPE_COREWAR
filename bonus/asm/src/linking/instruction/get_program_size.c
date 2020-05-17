/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_program_size
*/

#include "asm.h"

size_t get_program_size(instruct_t *instruct)
{
    size_t size = 0;

    for (; instruct; instruct = instruct->next) {
        if (!instruct)
            continue;
        size += instruct->size;
    }
    return (size);
}