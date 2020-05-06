/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_champions.c
*/

#include "my.h"
#include "champion.h"
#include "program.h"

int get_champions(champion_t **champions, int nbr_champions,
        program_t *programs)
{
    int i = -1;

    if (!champions || !programs)
        return 84;
    if (!(*champions = my_cmalloc(sizeof(champion_t) * (nbr_champions + 1))))
        return 84;
    while (++i < nbr_champions) {
        if (get_smallest_id_champion(&(*champions)[i], nbr_champions, programs) == 84)
            return 84;
    }
    return 0;
}