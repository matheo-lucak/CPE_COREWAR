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

#include "header_info.h"
#include "instruction.h"
#include "labels.h"

#include "queue.h"

typedef struct byte_parser_s
{
    int p1 : 2;
    int p2 : 2;
    int p3 : 2;
    int p4 : 2;
} byte_parser_t;

//Main structure of ASM
typedef struct asm_info_s
{
    header_info_t header_info;
    instruct_t *instructs;
    label_t *labels;
} asm_info_t;

bool parse_file(int fd, asm_info_t *asm_i);

#endif /* !ASM_H_ */