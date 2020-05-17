/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** byte_parser.h
*/

#ifndef CPE_COREWAR_2019_INSTR_PARAM_TYPES_H
#define CPE_COREWAR_2019_INSTR_PARAM_TYPES_H

typedef struct byte_parser_s
{
    unsigned char p1 : 2;
    unsigned char p2 : 2;
    unsigned char p3 : 2;
    unsigned char p4 : 2;
} byte_parser_t;

#endif //CPE_COREWAR_2019_INSTR_PARAM_TYPES_H
