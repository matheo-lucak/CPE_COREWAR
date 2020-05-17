/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return -1;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
