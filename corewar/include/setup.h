/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** core.h
*/

#ifndef CPE_COREWAR_2019_SETUP_H
#define CPE_COREWAR_2019_SETUP_H

#include "program.h"

typedef struct setup_s
{
    int ac;
    char **av;
    int nbr_cycle_dump;
    int nbr_programs;
    program_t *programs;
} setup_t;

bool check_opts(int ac, char **av);

int get_nbr_cycle_dump(int ac, char **av, int *nbr_cycle_dump);

int get_nbr_programs(int ac, char **av, int *nbr_programs);

int get_programs(int ac, char **av, int nbr_programs, program_t **programs);

int init_setup(setup_t *setup);

#endif //CPE_COREWAR_2019_SETUP_H
