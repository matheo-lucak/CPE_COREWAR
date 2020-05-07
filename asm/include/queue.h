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
} queue_t;

//List utils for queue
bool dequeue(queue_t **queue);
bool empty_queue(queue_t **queue);
bool enqueue(queue_t **queue, void *src_node, size_t size);

#endif /* !QUEUE_H_ */