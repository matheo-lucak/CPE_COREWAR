/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_program.c
*/

#include "program.h"

int get_program(int ac, char **av, int *index, program_t *program)
{
    if (!program || !av || !index)
        return 84;
    if (get_program_opts(ac, av, index, program) == 84)
        return 84;
    if (get_program_file(ac, av, index, program) == 84)
        return 84;
    if (parse_program_file(program) == 84)
        return 84;
    return 0;
}