/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_strlen.c
*/

int my_strlen_until(const char *str, char c)
{
    int i = -1;

    if (!str)
        return 0;
    while (str[++i] && str[i] != c);
    return i;
}