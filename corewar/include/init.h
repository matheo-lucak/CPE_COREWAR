/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init.h
*/

#ifndef CPE_COREWAR_2019_INIT_H
#define CPE_COREWAR_2019_INIT_H

#include "core.h"

bool check_opts(int ac, char **av);

int get_nbr_cycle_dump(int ac, char **av, int *nbr_cycle_dump);

int get_nbr_programs(int ac, char **av, int *nbr_programs);

int get_programs(int ac, char **av, int nbr_programs, program_t **programs);

int init_core(core_t *core);

#endif //CPE_COREWAR_2019_INIT_H
