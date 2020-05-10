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
        parsing_error(reader_i, "Multiple definition of the same label");
        return (true);
    }
    return (false);
}

bool fill_label(reader_info_t reader_i, char *label_name, asm_info_t *asm_i)
{
    label_t label;

    label.freer = (void *)&free_label;
    if (!label_name || !asm_i ||
        fill_label_error(reader_i, label_name, asm_i->labels))
        return (false);
    label.name = my_strdup(label_name);
    label.address = asm_i->writing_address;
    if (!(label.name))
        return (false);
    return (ENQUEUE(&(asm_i->labels), &label, label_t));
}