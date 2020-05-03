/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** program.h
*/

#ifndef CPE_COREWAR_2019_PROGRAM_H
#define CPE_COREWAR_2019_PROGRAM_H

#include <stdbool.h>

typedef struct program_s
{
    int id;
    char *name;
    void *load_address;
    void *registers;
    void *pc;
    bool carry;
} program_t;

#endif //CPE_COREWAR_2019_PROGRAM_H
