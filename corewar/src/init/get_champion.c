/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_champion.c
*/

#include <limits.h>
#include "my.h"
#include "champion.h"
#include "program.h"

static int get_champion(champion_t *champion, program_t *program)
{
    if (!champion || !program)
        return 84;
    if (!(champion->registers = my_cmalloc(REG_SIZE * REG_NUMBER)))
        return 84;
    if (my_memcpy(&program->id, &champion->registers[0], REG_SIZE) == 84)
        return 84;
    champion->pc = program->load_address;
    return 0;
}

int get_smallest_id_champion(champion_t *champion, int nbr_champions,
        program_t *programs)
{
    int i = -1;
    int index = 0;
    int smallest = INT_MAX;

    if (!champion || !programs)
        return 84;
    while (++i < nbr_champions) {
        if (programs[i].id != -1 && programs[i].id < smallest) {
            smallest = programs[i].id;
            index = i;
        }
    }
    return get_champion(champion, &programs[index]);
}