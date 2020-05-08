/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** labels
*/

#ifndef LABELS_H_
#define LABELS_H_

#include "op.h"
#include "parser.h"

#include "queue.h"

//Label linked list
//name corresponds to the label's name
//address corresponds to the offset in byte where the label has been found
typedef struct label_s
{
    struct label_s *next;
    char *name;
    int address;
} label_t;

//Finds a label corresponding with the given name and
//  returns his contained address
//Returns -1 if no corresponding label has been found
int get_label_address(label_t *label, char *label_name);

//Checks if a label corresponding to the given name exists in the list
//Returns true if label found
//Returns false in other cases
bool check_existing_label(label_t *label, char *label_name);

//Checks if the given string corresponds to a label
//A label is defined as a string ended by the LABEL_CHAR
//Returns true if the given corresponds to a label
//Returns false in all other cases
bool is_label(char *str);

//Checks if the given label_name is a valid label
//A valid label is a label which only contains LABEL_CHARS
//Returns true if the given label name is a valid label
//Returns false in all other cases
bool is_valid_label(reader_info_t reader_i, char *labe_name);

#endif /* !LABELS_H_ */