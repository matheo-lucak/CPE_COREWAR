/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser_params
*/

#ifndef PARSER_PARAMS_H_
#define PARSER_PARAMS_H_

#include "parser.h"

bool redirect_param(reader_info_t reader_i, char types, parameters_t *param,
                                                                char *line);

bool param_redirect_error(reader_info_t reader_i, char *line);

#endif /* !PARSER_PARAMS_H_ */