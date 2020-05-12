/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** program.h
*/

#ifndef CPE_COREWAR_2019_PROGRAM_H
#define CPE_COREWAR_2019_PROGRAM_H

#include <stdbool.h>
#include "op.h"

typedef struct program_s
{
    char *file;
    int id;
    int load_address;
    header_t header;
    char *instructions;
} program_t;

int get_program_opts(int ac, char **av, int *index, program_t *program);

int get_program_file(int ac, char **av, int *index, program_t *program);

int parse_program_file(program_t *program);

int get_program(int ac, char **av, int *index, program_t *program);

#endif //CPE_COREWAR_2019_PROGRAM_H
