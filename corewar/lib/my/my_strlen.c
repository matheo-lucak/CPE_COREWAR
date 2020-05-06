/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_strlen.c
*/

int my_strlen(const char *str)
{
    int i = -1;

    if (!str)
        return 0;
    while (str[++i]);
    return i;
}