/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_find_char
*/

int my_find_char(const char *str, char to_find)
{
    int index = 0;

    if (!str)
        return (-1);
    while (str[index]) {
        if (!(str[index] ^ to_find))
            return (index);
        index += 1;
    }
    return (-1);
}

int my_find_last_char(const char *str, char to_find)
{
    int index = 0;
    int save = -1;

    if (!str)
        return (-1);
    while (str[index]) {
        if (!(str[index] ^ to_find))
            save = index;
        index += 1;
    }
    return (save);
}