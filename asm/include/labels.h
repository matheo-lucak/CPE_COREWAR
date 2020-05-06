/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** labels
*/

#ifndef LABELS_H_
#define LABELS_H_

#include "queue.h"

typedef struct label_s
{
    struct label_s *next;
    char *name;
    int address;
} label_t;

#endif /* !LABELS_H_ */