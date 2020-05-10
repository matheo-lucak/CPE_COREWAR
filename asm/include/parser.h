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

#include <stddef.h>
#include <unistd.h>

#include "asm.h"

//Prints error_msg with a specific format
void parsing_error(reader_info_t reader_i, char *error_msg);

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
//Used to parse header (~body)
//Returns true in case of success
//Returns false if any error occurs
bool redirect_fill_header(reader_info_t reader_i, header_info_t *header_i);

//Sub fonction of redirec_parsing
//Used to parse body (~header)
//Returns true in case of success
//Returns false if any error occurs
bool redirect_body(reader_info_t reader_i, asm_info_t *asm_i);

//Adds a new label to the asm_info list of labels
//Returns true in case of success
//Returns false if any error occurs
bool fill_label(reader_info_t reader_i, char *label_name, asm_info_t *asm_i);

//Checks if the given label_name is a valid label
//A valid label is a label which only contains LABEL_CHARS
//Returns true if the given label name is a valid label
//Returns false in all other cases
bool is_valid_label(reader_info_t reader_i, char *labe_name);

//Adds a new instruction to the asm_info list of instructs
//Returns true in case of success
//Returns false if any error occurs
bool fill_instruction(reader_info_t reader_i, char **parsed_line,
                                                asm_info_t *asm_i);

//Sub fonction of fill_instruction
//Used to parse mnemonic (~params)
//Returns true in case of success
//Returns false if any error occurs
bool fill_mnemonic(reader_info_t reader_i, instruct_t *instruct,
                            char **parsed_line, asm_info_t *asm_i);

//Sub fonction of fill_instruction
//Used to parse params (~mnemonic)
//Returns true in case of success
//Returns false if any error occurs
bool fill_params(reader_info_t reader_i, instruct_t *instruct,
                        char **parsed_line, asm_info_t *asm_i);

//Sub fonction of full_params
//Translates all param types in one byte
void fill_param_code(instruct_t *instruct);

//Checks if given string corresponds to a register
//A register starts with 'r'
//Returns true if corresponds to a register
//Returns false in all other cases
bool param_is_register(char *str);

//Checks if given string corresponds to a direct
//A direct starts with DIRECT_CHAR ('%')
//Returns true if corresponds to a direct
//Returns false in all other cases
bool param_is_direct(char *str);

//Checks if given string corresponds to a label
//A label starts with LABEL_CHAR (':')
//Returns true if corresponds to a label
//Returns false in all other cases
bool param_is_label(char *str);

#endif /* !PARSER_H_ */