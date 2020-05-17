/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** my_puttab.c
*/

int my_putstr(char const *str);

int my_puttab(const char **tab)
{
    int i = 0;

    while (tab[i]) {
        if (my_putstr(tab[i]) == 84)
            return 84;
        ++i;
    }
    return 0;
}
