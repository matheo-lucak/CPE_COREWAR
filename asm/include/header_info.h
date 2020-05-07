/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** header_info
*/

#ifndef HEADER_INFO_H_
#define HEADER_INFO_H_

#include <stdbool.h>
#include "op.h"

#include "parser.h"

typedef struct header_info_s
{
    header_t header;
    bool name_set;
    bool comment_set;
    bool parsing_core;
} header_info_t;

bool is_header(char *line, char *cmd_string);

bool redirect_fill_header(reader_info_t reader_i, header_info_t *header_i);

#endif /* !HEADER_INFO_H_ */
