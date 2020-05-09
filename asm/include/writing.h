/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** writing
*/

#ifndef WRITING_H_
#define WRITING_H_

#include "asm.h"

//Writes given header in the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_header(int fd, header_info_t header_i);


//Writes all instructions in the given fd
//Returns true in case of success
//Returns false in all other cases
bool write_body(int fd, instruct_t *instructs);

#endif /* !WRITING_H_ */