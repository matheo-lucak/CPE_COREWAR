/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** core.h
*/

#ifndef CPE_COREWAR_2019_CORE_H
#define CPE_COREWAR_2019_CORE_H

#include "program.h"

typedef struct core_s
{
    int ac;
    char **av;
    int nbr_cycle_dump;
    int nbr_programs;
    program_t *programs;
} core_t;

#endif //CPE_COREWAR_2019_CORE_H
