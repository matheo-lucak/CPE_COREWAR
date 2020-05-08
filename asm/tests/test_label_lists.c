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

Test(label_list_tests, no_label_found_1)
{
    label_t *queue = NULL;
    label_t node = {NULL, "HEAD", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(!check_existing_label(queue, "Mais"));
}

Test(label_list_tests, no_label_found_2)
{
    label_t *queue = NULL;

    cr_assert(!check_existing_label(queue, "Ou"));
}

Test(label_list_tests, no_label_found_3)
{
    label_t *queue = NULL;
    label_t node = {NULL, "est ", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(!check_existing_label(queue, "est"));
}

Test(label_list_tests, label_found_1)
{
    label_t *queue = NULL;
    label_t node = {NULL, "Charlie !", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(check_existing_label(queue, "Charlie !"));
}

Test(label_list_tests, no_label_found_address_1)
{
    label_t *queue = NULL;

    cr_assert(get_label_address(queue, "test1") == -1);
}

Test(label_list_tests, no_label_found_address_2)
{
    label_t *queue = NULL;
    label_t node = {NULL, "Ceci n'est pas une pipe", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(get_label_address(queue, "test1") == -1);
}

Test(label_list_tests, no_label_found_address_3)
{
    label_t *queue = NULL;
    label_t node = {NULL, "oui", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(get_label_address(queue, "stiti") == -1);
}

Test(label_list_tests, label_found_address_1)
{
    label_t *queue = NULL;
    label_t node = {NULL, "do", 10};

    enqueue((void *)&queue, &node, sizeof(label_t));
    cr_assert(get_label_address(queue, "do") == 10);
}