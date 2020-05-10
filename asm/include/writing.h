/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** writing
*/

#ifndef WRITING_H_
#define WRITING_H_

#include <unistd.h>

#include "asm.h"

//Writes given header into the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_header(int fd, header_t header);

//Writes all instructions into the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_body(int fd, instruct_t *instructs);


//Writes one instruction into the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_instruction(int fd, instruct_t *instruct);

//Writes all instructions's params into the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_params(int fd, instruct_t *instruct);

#endif /* !WRITING_H_ */