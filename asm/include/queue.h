/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** queue
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

//Structure usefull for heritage
typedef struct queue_s
{
    struct queue_s *next;
    bool (*freer)(void *);
} queue_t;

//List utils for queue
bool dequeue(queue_t **queue);
bool empty_queue(queue_t **queue);
bool enqueue(queue_t **queue, void *src_node, size_t size);

#define ENQUEUE(queue, node, type) (enqueue(\
                (queue_t **)queue, (void *)node, sizeof(type)))
#define DEQUEUE(queue) (dequeue((queue_t **)queue))
#define EMPTY_QUEUE(queue) (empty_queue((queue_t **)queue))

#endif /* !QUEUE_H_ */