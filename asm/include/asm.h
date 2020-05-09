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

#include "labels.h"
#include "instruction.h"
#include "header_info.h"

#include "queue.h"

//file extension of the asm compiled binary files
#define COR_EXT ".cor"

//Structure for accessing 2bit per 2bit in a byte
typedef struct __attribute__((packed)) byte_parser_s
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
    size_t writing_address;
} asm_info_t;

#define CAST_BYTE_PARSER(c) (*(byte_parser_t *)&c)

//Main functions of asm
//Opens all paths
//Parse them
//link them
//Write them in a file corresponding to the first read file[.s] with [.cor] ext
bool asm_core(const char *paths[]);

//Writes header and all instructions in a file
//Returns true in case of success
//Returns false in all other cases
bool write_file(const char *path, asm_info_t asm_i);

//Returns the program size
//Program size corresponds to the summ of instructions size
size_t get_program_size(instruct_t *instruct);

//Links all label variable in instructs's params by
//the difference between the instruct's address and the found label address
//Returns true in case of success
//Returns false in all other cases
bool link_labels(label_t *label, instruct_t *instruct);

#endif /* !ASM_H_ */