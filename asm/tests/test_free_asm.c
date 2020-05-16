/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_free_asm
*/

#include <criterion/criterion.h>
#include "asm.h"
#include "my.h"

Test(free_asm, error_1)
{
    cr_assert(!free_asm(NULL));
}

Test(free_asm, free_asm_labels)
{
    asm_info_t asm_i = {0};
    label_t node = {NULL, (void *)&free_label, my_strdup("florian"), 10};

    if (!ENQUEUE(&(asm_i.labels), &node, label_t))
        cr_assert(0);
    cr_assert(free_asm(&asm_i));
}

Test(free_asm, free_asm_instructs)
{
    asm_info_t asm_i = {0};
    instruct_t node = {0};

    node.freer = (void *)&free_instruct;
    node.prog_name = my_strdup("letoucan");
    node.param_nb = 1;
    node.params[0].has_label = true;
    node.params[0].label_name = my_strdup("jesuislelabel");
    if (!ENQUEUE(&(asm_i.instructs), &node, instruct_t))
        cr_assert(0);
    cr_assert(free_asm(&asm_i));
}