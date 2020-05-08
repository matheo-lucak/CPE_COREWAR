/*
** EPITECH PROJECT, 2020
** asm
** File description:
** test_label_lists
*/

#include <criterion/criterion.h>
#include "labels.h"
#include "my.h"

Test(label_list_tests, enqueue_label_1)
{
    label_t *queue = NULL;
    label_t node = {NULL, "HEAD", 10};

    cr_assert(enqueue((void *)&queue, &node, sizeof(label_t)));
}

Test(label_list_tests, enqueue_label_2)
{
    label_t *queue = NULL;
    label_t node = {NULL, "HEAD", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(queue && !(queue->next) && !my_strcmp(queue->name, node.name) &&
                queue->address == node.address);
}

