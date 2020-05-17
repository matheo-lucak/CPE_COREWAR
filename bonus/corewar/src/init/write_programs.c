/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** write_champions.c
*/

#include "program.h"

static int write_program(program_t *program, char *memory)
{
    int i = -1;
    int address = 0;

    if (!program || !memory)
        return 84;
    address = program->load_address;
    while (++i < program->header.prog_size) {
        memory[address] = program->instructions[i];
        ++address;
        address %= MEM_SIZE;
    }
    return 0;
}

int write_programs(program_t *programs, int nbr_programs, char *memory)
{
    int i = -1;

    if (!programs || !memory)
        return 84;
    while (++i < nbr_programs) {
        if (write_program(&programs[i], memory) == 84)
            return 84;
    }
    return 0;
}