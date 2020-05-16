/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_count_char
*/

#include "my.h"

int my_count_char(const char *str, char c)
{
    register int index = 0;
    int counter = 0;

    for (; str && str[index]; index += 1) {
        if (str[index] == c)
            counter += 1;
    }
    return (counter);
}