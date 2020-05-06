/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_dequeue
*/

#include <criterion/criterion.h>
#include "queue.h"

Test(queue_tests, dequeue_fail)
{
    queue_t *queue = NULL;

    cr_assert(!dequeue(&queue));
}

Test(queue_tests, dequeue_fail_2)
{
    cr_assert(!dequeue(NULL));
}

Test(queue_tests, dequeue_success)
{
    queue_t *queue = malloc(sizeof(queue_t));

    if (!queue)
        cr_assert(1);
    queue->next = NULL;
    dequeue(&queue);
    cr_assert(!queue);
}

Test(queue_tests, empty_queue_fail)
{
    cr_assert(!empty_queue(NULL));
}

Test(queue_tests, empty_queue_success_1)
{
    queue_t *node1 = malloc(sizeof(queue_t));
    queue_t *node2 = malloc(sizeof(queue_t));

    if (!node1 || !node2)
        cr_assert(1);
    node1->next = node2;
    node2->next = NULL;
    empty_queue(&node1);
    cr_assert(!node1);
}

Test(queue_tests, empty_queue_success_2)
{
    queue_t *node1 = malloc(sizeof(queue_t));
    queue_t *node2 = malloc(sizeof(queue_t));

    if (!node1 || !node2)
        cr_assert(1);
    node1->next = node2;
    node2->next = NULL;
    cr_assert(empty_queue(&node1));
}