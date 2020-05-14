/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** dump_memory.c
*/

#include "op.h"
#include "my.h"

int dump_memory(char *memory)
{
    int i = -1;

    while (++i < MEM_SIZE) {
        if (i != 0 && i % 32 == 0 && my_putchar('\n') == 84)
            return 84;
        if (i % 32 != 0 && my_putchar(' ') == 84)
            return 84;
        if ((unsigned char)memory[i] < 16 && my_putchar('0') == 84)
            return 84;
        if (my_put_signed_long_base((unsigned char)memory[i],
                "0123456789ABCDEF") == 84)
            return 84;


    }
    if (my_putchar('\n') == 84)
        return 84;
    return 0;
}