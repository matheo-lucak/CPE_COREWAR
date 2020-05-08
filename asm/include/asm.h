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

#include "parser.h"

#include "header_info.h"
#include "instruction.h"
#include "labels.h"

#include "queue.h"

//Structure for accessing 2bit per 2bit in a byte
typedef struct __attribute__((packed)) byte_parser_s
{
    int p1 : 2;
    int p2 : 2;
    int p3 : 2;
    int p4 : 2;
} byte_parser_t;

#define CAST_BYTE_PARSER(c) (*(byte_parser_t *)&c)

//Main structure of ASM
typedef struct asm_info_s
{
    header_info_t header_info;
    instruct_t *instructs;
    label_t *labels;
} asm_info_t;

//Parses an entire file (opened with fd contained in reader_i)
//Returns true in case of success
//Returns false if any error occurs
bool parse_file(reader_info_t reader_i, asm_info_t *asm_i);

//Redirects the given reader_info to be parsed and analysed
//Make sure to have a correct fd set in reader_i
//Returns true in case of success
//Returns false if any error occurs
bool redirect_parsing(reader_info_t reader_i, asm_info_t *asm_i);

//Sub fonction of redirec_parsing
//Used to parse body (~Header)
//Returns true in case of success
//Returns false if any error occurs
bool redirect_body(reader_info_t reader_i, asm_info_t *asm_i);

#endif /* !ASM_H_ */