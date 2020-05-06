/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_nbr_programs.c
*/

int get_nbr_programs(int ac, char **av, int *nbr_programs)
{
    int i = 0;

    if (!av || !nbr_programs)
        return 84;
    while (++i < ac) {
        if (av[i][0] != '-')
            ++*nbr_programs;
        if (av[i][0] == '-')
            ++i;
    }
    if (*nbr_programs == 0)
        return 84;
    return 0;
}