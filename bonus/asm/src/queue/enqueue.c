/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** enqueue
*/

#include "my.h"
#include "queue.h"

static void enqueue_first_node(queue_t **queue,
                                    queue_t *new_node)
{
    (*queue) = new_node;
}

static void enqueue_new_node(queue_t *queue,
                                    queue_t *new_node)
{
    for (; queue->next; queue = queue->next);
    queue->next = new_node;
}

bool enqueue(queue_t **queue, void *src_node, size_t size)
{
    void *new_node = NULL;

    if (!queue || !src_node || size < sizeof(queue_t))
        return (false);
    new_node = malloc(size);
    if (!new_node)
        return (false);
    my_memcpy(new_node, src_node, size);
    ((queue_t *)new_node)->next = NULL;
    if (!(*queue))
        enqueue_first_node(queue, (queue_t *)new_node);
    else
        enqueue_new_node(*queue, (queue_t *)new_node);
    return (true);
}