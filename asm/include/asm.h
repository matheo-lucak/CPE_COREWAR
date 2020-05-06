/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdbool.h>
#include "op.h"

typedef struct byte_parser_s
{
    int p1 : 2;
    int p2 : 2;
    int p3 : 2;
    int p4 : 2;
} byte_parser_t;

#endif /* !ASM_H_ */