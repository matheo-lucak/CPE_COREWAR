/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_dequeue_children
*/

#include <criterion/criterion.h>
#include "my.h"
#include "instruction.h"
#include "labels.h"
#include "queue.h"

Test(queue_tests, dequeue_label_1)
{
    label_t *queue = NULL;
    label_t node = {NULL, (void *)&free_label, my_strdup("florian"), 10};

    if (!ENQUEUE(&queue, &node, label_t))
        cr_assert(0);
    cr_assert(DEQUEUE(&queue));
}

Test(queue_tests, dequeue_instruct_1)
{
    instruct_t *queue = NULL;
    instruct_t node = {0};

    node.freer = (void *)&free_instruct;
    node.prog_name = my_strdup("letoucan");
    node.param_nb = 1;
    node.params[0].has_label = true;
    node.params[0].label_name = my_strdup("jesuislelabel");
    if (!ENQUEUE(&queue, &node, instruct_t))
        cr_assert(0);
    cr_assert(DEQUEUE(&queue));
}

Test(queue_tests, free_instruct_error)
{
    cr_assert(!free_instruct(NULL));
}

Test(queue_tests, free_label_error)
{
    cr_assert(!free_label(NULL));
}