/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** dump_memory.c
*/

#include "op.h"
#include "my.h"

static bool is_printable_char(char c)
{
    if (c < 32 || c > 126)
        return (false);
    return (true);
}

static int translate_memory_table(char *memory, int i)
{
    i -= 32;
    if (i < 0)
        return 84;
    my_putstr(" |");
    for (;i < 32; i += 1) {
        if (is_printable_char(memory[i]))
            my_putchar(memory[i]);
        else
            my_putchar('.');
    }
    my_putstr("|\n");
}

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