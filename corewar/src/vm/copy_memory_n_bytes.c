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
    int address = 0;

    if (!memory || !pc || !dest)
        return 84;
    address = *pc + n - 1;
    address %= MEM_SIZE;
    while (i < n) {
        ((char *)dest)[i] = memory[address];
        ++i;
        ++*pc;
        *pc %= MEM_SIZE;
        --address;
        if (address < 0)
            address = MEM_SIZE - 1;
    }
    return 0;
}

int write_memory_n_bytes(char *memory, int *pc, void *src, int n)
{
    int i = 0;
    int address = 0;

    if (!memory || !pc || !src)
        return 84;
    address = *pc + n - 1;
    address %= MEM_SIZE;
    while (i < n) {
        memory[address] = ((char *)src)[i];
        ++i;
        ++*pc;
        *pc %= MEM_SIZE;
        --address;
        if (address < 0)
            address = MEM_SIZE - 1;
    }
    return 0;
}