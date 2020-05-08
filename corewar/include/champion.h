/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** champion.h
*/

#ifndef CPE_COREWAR_2019_CHAMPION_H
#define CPE_COREWAR_2019_CHAMPION_H

#include <stdbool.h>
#include "op.h"
#include "program.h"

typedef struct champion_s
{
    void *registers;
    char *pc;
    bool carry;
    int cycles_left;
} champion_t;

int get_smallest_id_champion(champion_t *champion, int nbr_champions,
        program_t *programs);

#endif //CPE_COREWAR_2019_CHAMPION_H
