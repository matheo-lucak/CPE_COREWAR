/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** Created by croquette
*/

int my_atoi(char const *str)
{
    int neg = 1;
    unsigned int nb = 0;

    if (!str)
        return 0;
    while (*str && (*str == '-' || *str == '+')) {
        neg *= (*str == '-') ? -1 : 1;
        ++str;
    }
    while (*str && *str >= '0' && *str <= '9') {
        nb *= 10;
        nb += *str - 48;
        ++str;
    }
    return (int) nb * neg;
}
