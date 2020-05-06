/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putchar(char c);

int my_strlen(const char *str);

int my_putstr(const char *str)
{
    int len = my_strlen(str);

    if (!len || !str)
        return 0;
    if (write(1, str, len) == -1)
        return 84;
    return 0;
}
