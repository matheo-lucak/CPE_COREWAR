/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** dequeue
*/

#include "queue.h"

bool dequeue(queue_t **queue)
{
    queue_t *save = NULL;

    if (!queue || !(*queue))
        return (false);
    save = *queue;
    *queue = (*queue)->next;
    free(save);
    return (true);
}