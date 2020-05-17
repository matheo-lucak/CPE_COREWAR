/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_names.c
*/

#include "my.h"
#include "program.h"

int get_names(program_t *programs, int nbr_programs, char ***names)
{
    int i = -1;

    if (!programs || !names)
        return 84;
    if (!(*names = my_cmalloc(sizeof(char *) * (nbr_programs + 1))))
        return 84;
    while (++i < nbr_programs) {
        if (!((*names)[i] = my_strdup(programs[i].header.prog_name)))
            return 84;
    }
    return 0;
}