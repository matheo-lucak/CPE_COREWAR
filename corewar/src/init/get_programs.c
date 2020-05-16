/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_programs.c
*/

#include "my.h"
#include "program.h"

static int get_smallest_free_id(program_t *programs, int index)
{
    int i = -1;
    int smallest = 1;

    if (!programs)
        return 84;
    while (++i < index) {
        if (programs[i].id == smallest)
            ++smallest;
    }
    programs[i].id = smallest;
    return 0;
}

static int get_load_address(program_t *program, int i, int nbr_programs)
{
    int address = MEM_SIZE / nbr_programs * i;

    if (!program)
        return 84;
    if (program->spec_address == false)
        program->load_address = address;
    return 0;
}

int get_programs(int ac, char **av, int nbr_programs, program_t **programs)
{
    int i = -1;
    int index = 0;

    if (!av || !programs)
        return 84;
    if (!(*programs = my_cmalloc(sizeof(program_t) * (nbr_programs + 1))))
        return 84;
    while (++i < nbr_programs) {
        if (get_smallest_free_id(*programs, i) == 84)
            return 84;
        if (get_program(ac, av, &index, &(*programs)[i]) == 84)
            return 84;
        if (get_load_address(&(*programs)[i], i, nbr_programs) == 84)
            return 84;
    }
    return 0;
}