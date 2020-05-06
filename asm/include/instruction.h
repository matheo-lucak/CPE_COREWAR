/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instruction
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "op.h"
#include "queue.h"

typedef struct instruction_s
{
    struct instruction_s *next;
    char code;
    char param_types;
} instruct_t;

#endif /* !INSTRUCTION_H_ */