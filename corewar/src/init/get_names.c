/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_names.c
*/

#include "my.h"
#include "program.h"
#include "champion.h"

static int get_name(char **name, int id, int nbr_programs, program_t *programs)
{
    int i = -1;

    if (!name || !programs)
        return 84;
    if (!(*name = my_cmalloc(sizeof(char) * (PROG_NAME_LENGTH + 1))))
        return 84;
    while (++i < nbr_programs) {
        if (programs[i].id == id &&
            my_memcpy(programs->header.prog_name, *name,
                    PROG_NAME_LENGTH) == 84)
            return 84;
    }
    return 0;
}

int get_names(char ***names, int nbr_champions,
        champion_t *champions, program_t *programs)
{
    int i = -1;

    if (!names || !champions || !programs)
        return 84;
    if (!(*names = my_cmalloc(sizeof(char *) * (nbr_champions + 1))))
        return 84;
    while (++i < nbr_champions) {
        if (get_name(&(*names)[i], ((int *)champions[i].registers)[0],
                nbr_champions, programs) == 84)
            return 84;
    }
    return 0;
}