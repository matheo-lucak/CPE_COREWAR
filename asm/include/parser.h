/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

//Structure for reading a file
//fd corresponds to the file descriptor of the file readed
//name corresponds to the name of the file readed
//line is the current line read
//line_nb is the nth line read
typedef struct reader_info_s
{
    int fd;
    char *name;
    char *line;
    unsigned int line_nb;
} reader_info_t;

#endif /* !PARSER_H_ */