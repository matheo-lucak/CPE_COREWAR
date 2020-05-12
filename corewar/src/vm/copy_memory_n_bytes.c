/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** copy_memory_n_bytes.c
*/

#include "op.h"

int copy_memory_n_bytes(const char *memory, int *pc, void *dest, int n)
{
    int i = 0;

    if (!memory || !pc || !dest)
        return 84;
    while (i < n) {
        ((char *)dest)[i] = memory[*pc];
        ++i;
        ++*pc;
        *pc %= MEM_SIZE;
    }
    return 0;
}

int write_memory_n_bytes(char *memory, int *pc, void *src, int n)
{
    int i = 0;

    if (!memory || !pc || !src)
        return 84;
    while (i < n) {
        memory[*pc] = ((char *)src)[i];
        ++i;
        ++*pc;
        *pc %= MEM_SIZE;
    }
    return 0;
}