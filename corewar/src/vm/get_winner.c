/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** check_winner.c
*/

#include "my.h"
#include "champion.h"

static int print_name(char *name)
{
    int i = -1;

    while (++i < PROG_NAME_LENGTH && name[i]) {
        if (my_putchar(name[i]) == 84)
            return 84;
    }
    return 0;
}

static int print_winner(champion_t *champion)
{
    if (!champion)
        return 84;
    if (my_putstr("The player ") == 84)
        return 84;
    if (my_put_signed_long_base(champion->id, "0123456789") == 84)
        return 84;
    if (my_putchar('(') == 84)
        return 84;
    if (print_name(champion->name) == 84)
        return 84;
    if (my_putstr(") has won.") == 84)
        return 84;
    return 0;
}

int get_winner(champion_t *champions, int nbr_champions, int id)
{
    int i = -1;

    if (!champions)
        return 84;
    while (++i < nbr_champions) {
        if (champions[i].id == id &&
            print_winner(&champions[i]) == 84)
            return 84;
    }
    return 0;
}
