/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** my_swap_int_endian.c
*/

int my_swap_int_endian(int *value)
{
    int bytes[4] = {0};

    if (!value)
        return 84;
    bytes[0] = (*value & 0x000000ff) << 24;
    bytes[1] = (*value & 0x0000ff00) << 8;
    bytes[2] = (*value & 0x00ff0000) >> 8;
    bytes[3] = (*value & 0xff000000) >> 24;
    *value = bytes[0] | bytes[1] | bytes[2] | bytes[3];
    return 0;
}