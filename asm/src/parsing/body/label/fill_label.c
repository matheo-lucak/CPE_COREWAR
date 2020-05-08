/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_label
*/

#include "parser.h"
#include "my.h"

static bool fill_label_error(reader_info_t reader_i, char * label_name,
                                                        label_t *labels)
{
    if (check_existing_label(labels, label_name)) {
        my_printf("asm, %s, line %d: Multiple definition of the same label.\n"
                                            , reader_i.name, reader_i.line_nb);
        return (true);
    }
    return (false);
}

bool fill_label(reader_info_t reader_i, char *label_name, asm_info_t *asm_i)
{
    label_t new_label;

    if (!label_name || !asm_i ||
        fill_label_error(reader_i, label_name, asm_i->labels))
        return (false);
    new_label.name = my_strdup(label_name);
    new_label.address = asm_i->writing_address;
    if (!(new_label.name))
        return (false);
    return (ENQUEUE(&(asm_i->labels), &new_label, label_t));
}