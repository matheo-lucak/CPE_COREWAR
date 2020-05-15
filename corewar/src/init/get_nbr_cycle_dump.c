/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_nbr_cycle_dump.c
*/

#include "my.h"
#include "setup.h"

static bool check_nbr_cycle_dump(char *str)
{
    int i = -1;

    if (!str)
        return false;
    while (str[++i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int get_nbr_cycle_dump(int ac, char **av, int *nbr_cycle_dump)
{
    bool found = false;
    int i = -1;

    if (!av || !nbr_cycle_dump)
        return 84;
    *nbr_cycle_dump = -1;
    while (++i < ac) {
        if (!my_strcmp(av[i], "-dump") &&
            (found == true ||
            check_nbr_cycle_dump(av[i + 1]) == false))
            return 84;
        if (!my_strcmp(av[i], "-dump")) {
            found = true;
            *nbr_cycle_dump = my_atoi(av[i + 1]);
        }
    }
    return 0;
}