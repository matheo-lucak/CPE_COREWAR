/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_asm
*/

#include "asm.h"

bool free_asm(asm_info_t *asm_i)
{
    if (!asm_i)
        return (false);
    EMPTY_QUEUE(&(asm_i->instructs));
    EMPTY_QUEUE(&(asm_i->labels));
    return (true);
}