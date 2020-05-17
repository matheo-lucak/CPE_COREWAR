/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_open_file
*/

#include <criterion/criterion.h>
#include "open.h"
#include "writing.h"

Test(open_file, open_reader_error_1)
{
    reader_info_t reader_i = open_file_reader(NULL);

    cr_assert(reader_i.fd == -1);
}

Test(open_file, open_reader_success_1)
{
    reader_info_t reader_i = open_file_reader("tests/test_open_file.c");

    cr_assert(reader_i.fd != -1);
}


Test(open_file, open_writer_error_1)
{
    cr_assert(open_file_writer(NULL) == -1);
}

Test(open_file, open_writer_success_1)
{
    cr_assert(open_file_writer("tests/test1") != -1);
}

Test(open_file, open_writer_success_2)
{
    cr_assert(open_file_writer("tests/test2.s") != -1);
}