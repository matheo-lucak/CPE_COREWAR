/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_write_header
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "open.h"
#include "writing.h"

Test(write_header, bad_fd)
{
    header_t header;

    cr_assert(!write_header(-1, header));
}

Test(write_header, corrupted_fd)
{
    header_t header;

    close(1);
    cr_assert(!write_header(1, header));
}