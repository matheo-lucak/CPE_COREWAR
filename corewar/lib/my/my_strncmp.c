/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return -1;
    while (s1[i] && s2[i] && s1[i] == s2[i] && (i < n || n < 0))
        i++;
    if (i == n)
        return s1[i - 1] - s2[i - 1];
    return s1[i] - s2[i];
}
