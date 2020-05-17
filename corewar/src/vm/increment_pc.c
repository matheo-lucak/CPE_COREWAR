/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** increment_pc.c
*/

#include <sys/types.h>
#include "op.h"

int increment_pc(int pc, ssize_t increment)
{
    pc += increment;
    if (pc < 0)
        pc += MEM_SIZE;
    pc %= MEM_SIZE;
    return pc;
}