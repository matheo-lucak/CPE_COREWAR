/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_enqueue
*/

#include <criterion/criterion.h>
#include "queue.h"

Test(queue_tests, enqueue_fail_1)
{
    cr_assert(!enqueue(NULL, NULL, 0));
}

Test(queue_tests, enqueue_fail_2)
{
    queue_t *head = NULL;

    cr_assert(!enqueue(&head, NULL, 0));
}

Test(queue_tests, enqueue_fail_3)
{
    queue_t *head = NULL;

    cr_assert(!enqueue(&head, NULL, sizeof(queue_t)));
}

Test(queue_tests, enqueue_fail_4)
{
    queue_t *head = NULL;
    queue_t node = {.next = NULL};

    cr_assert(!enqueue(&head, &node, 0));
}

Test(queue_tests, success_1)
{
    queue_t *head = NULL;
    queue_t node = {NULL};

    cr_assert(enqueue(&head, &node, sizeof(queue_t)));
}

Test(queue_tests, success_2)
{
    queue_t *head = NULL;
    queue_t node = {NULL};

    if (!enqueue(&head, &node, sizeof(queue_t)))
        cr_assert(1);
    cr_assert(head);
}