/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_add.c
*/

#include "vm.h"
#include "champion.h"
#include "byte_parser.h"

int instruction_add(vm_t *vm, champion_t *champion)
{
    byte_parser_t params = {0};

    if (!vm || !champion)
        return 84;
    ++champion->pc;


    return 0;
}