/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** Prints done the asm usage onto the stdout.
*/

#include "my.h"
#include "asm_usage.h"

bool print_asm_usage(void)
{
    ssize_t usage_len = my_strlen(asm_usage);
    ssize_t written_bytes = -1;

    written_bytes = write(1, asm_usage, usage_len);
    return ((written_bytes == usage_len) & (written_bytes > 0));
}