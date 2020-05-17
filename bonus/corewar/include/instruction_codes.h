/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instructions_names.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_CODES_H
#define CPE_COREWAR_2019_INSTRUCTION_CODES_H

typedef enum instruction_code_e
{
    i_live,
    i_ld,
    i_st,
    i_add,
    i_sub,
    i_and,
    i_or,
    i_xor,
    i_zjmp,
    i_ldi,
    i_sti,
    i_fork,
    i_lld,
    i_lldi,
    i_lfork,
    i_aff
} instr_code_t;

#endif //CPE_COREWAR_2019_INSTRUCTION_CODES_H
