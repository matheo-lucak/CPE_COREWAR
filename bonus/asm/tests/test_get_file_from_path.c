/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_get_file_from_path
*/

#include <criterion/criterion.h>
#include "open.h"
#include "my.h"

Test(get_file_from_path, error_1)
{
    cr_assert(!get_file_from_path(NULL));
}

Test(get_file_from_path, simple_name)
{
    char *path = get_file_from_path("file_name");

    cr_assert(path && !my_strcmp(path, "file_name"));
}

Test(get_file_from_path, simple_name_with_simple_path)
{
    char *path = get_file_from_path("path/file_name");

    cr_assert(path && !my_strcmp(path, "file_name"));
}

Test(get_file_from_path, name_with_ext)
{
    char *path = get_file_from_path("file_name.s");

    cr_assert(path && !my_strcmp(path, "file_name.s"));
}

Test(get_file_from_path, name_with_ext_n_path)
{
    char *path = get_file_from_path("pwd/file_name.s");

    cr_assert(path && !my_strcmp(path, "file_name.s"));
}