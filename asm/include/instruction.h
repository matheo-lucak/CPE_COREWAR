/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instruction
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "op.h"

#include <stdbool.h>
#include <stddef.h>

union param_storage
{
    int dir : DIR_SIZE * 8;
    int ind : IND_SIZE * 8;
    unsigned reg : 1 * 8;
};

//Parameters found in Instruction structure
//type corresponds to the parameter's type
//size corresponds to the size of the parameters, depending his type
//value corresponds to the value of the parameters
//label_name corresponds to the label name if one has been found.
//  Else equals NULL
typedef struct parameters_s
{
    int type;
    int size;
    union param_storage value;
    bool has_label;
    char *label_name;
    char types;
} parameters_t;

//Instruction linked list
//code corresponds to the mnemonic coding byte
//params_types corresponds to 4 2coding bit, one for each param
//params //
//size corresponds of the size in byte of the instruction
//line_nb corresponds to the line
//  where the instruction has been found
//address corresponds to the offset in byte
//  where the instruction should be written
typedef struct instruction_s
{
    struct instruction_s *next;
    bool (*freer)(void *);
    char code;
    char param_type_code;
    parameters_t params[MAX_ARGS_NUMBER];
    char params_types[MAX_ARGS_NUMBER];
    unsigned param_nb : MAX_ARGS_NUMBER;
    int size;
    size_t address;
    char *prog_name;
    unsigned int line_nb;
} instruct_t;

#include "queue.h"

//Frees instruct allocated components
//Returns true in case of success
//Returns false in any other cases
bool free_instruct(instruct_t *instruct);

#endif /* !INSTRUCTION_H_ */