/*
** EPITECH PROJECT, 2019
** Library
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return 84;
    return 0;
}
