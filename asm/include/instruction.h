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

union param_storage
{
    int ind : IND_SIZE * 8;
    int dir : DIR_SIZE * 8;
    int reg : REG_SIZE * 8;
};

typedef struct parameters_s
{
    int type;
    int size;
    union param_storage value;
    bool has_label;
    char *label_name;
} parameters_t;

typedef struct instruction_s
{
    struct instruction_s *next;
    char code;
    char params_types;
    parameters_t params[MAX_ARGS_NUMBER];
    int size;
    size_t address;
} instruct_t;

#endif /* !INSTRUCTION_H_ */