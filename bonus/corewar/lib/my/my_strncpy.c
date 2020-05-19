/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncpy.c
*/

int my_strncpy(char **dest, char const *src, int n)
{
    int i = -1;

    if (!dest || !src || n < 0)
        return 84;
    if (!*dest)
        return 84;
    while (++i < n && src[i]) {
        (*dest)[i] = src[i];
    }
    if (i < n)
        (*dest)[i] = '\0';
    return 0;
}
