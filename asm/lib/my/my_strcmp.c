/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares the fst difference between two strings by returning the difference
*/

int my_strcmp(char *s1, char *s2)
{
    register int index = 0;

    if (!s1 || !s2)
        return (0);
    while (s1[index] && s2[index]) {
        if (s1[index] > s2[index])
            return (1);
        if (s1[index] < s2[index])
            return (-1);
        index += 1;
    }
    if (!s1[index] && s2[index])
        return (-1);
    if (!s2[index] && s1[index])
        return (1);
    return (0);
}
