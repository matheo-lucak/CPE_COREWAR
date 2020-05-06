/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** empty_queue
*/

#include "queue.h"

bool empty_queue(queue_t **queue)
{
    if (!queue)
        return (false);
    while (*queue)
        dequeue(queue);
    return (true);
}