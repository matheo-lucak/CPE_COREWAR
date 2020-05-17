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
    int pc;
    bool carry;
    int cycles_left;
    int id;
    int last_live;
    bool dead;
    char name[PROG_NAME_LENGTH];
} champion_t;

int get_champion(champion_t *champion, program_t *program);

int get_smallest_id_champion(champion_t *champion, int nbr_champions,
        program_t *programs, int *last_id);

#endif //CPE_COREWAR_2019_CHAMPION_H
