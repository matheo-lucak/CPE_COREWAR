/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open
*/

#ifndef OPEN_H_
#define OPEN_H_

#include "parser.h"

//Returns an allocated string corresponding to the file name
//found at the given path
//Retuns NULL in case of error
char *get_file_from_path(const char *path);

//Opens a file with the given path
//Sets the reader_info_t's fd to opened fd
//Sets the reader_info_t's name to the opened file name
reader_info_t open_file_reader(const char *path);

//Opens a file named to the file from the given path
//Returns the file descriptor of the opened file
//Returns -1 in case of error
int open_file_writer(const char *path);

#endif /* !OPEN_H_ */