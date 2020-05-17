/*
** EPITECH PROJECT, 2019
** mul_my_runner_2019
** File description:
** my_tablen.c
*/

int my_tablen(void **tab)
{
    int i = -1;

    if (!tab)
        return 0;
    while (tab[++i]);
    return i;
}