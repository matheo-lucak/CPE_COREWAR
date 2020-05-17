/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_asm
*/

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <criterion/criterion.h>
#include "my.h"
#include "asm.h"

Test(asm_core, test_1_simple_file)
{
    const char *paths[] = {"tests/test_files/test1.s", NULL};
    struct stat sb[2];
    void *buff[2] = {NULL, NULL};
    int fd[2];

    if (!asm_core(paths))
        cr_assert(0);
    fd[0] = open("tests/test_files/test1.cor", O_RDONLY);
    fd[1] = open("test1.cor", O_RDONLY);
    if (fd[0] == -1 || fd[1] == -1 ||
        fstat(fd[0], sb) == -1 || fstat(fd[1], sb + 1) == -1 ||
        sb[0].st_size != sb[1].st_size)
        cr_assert(0);
    buff[0] = mmap(NULL, sb[0].st_size, PROT_READ, MAP_PRIVATE, fd[0], 0);
    buff[1] = mmap(NULL, sb[1].st_size, PROT_READ, MAP_PRIVATE, fd[1], 0);
    cr_assert(buff[0] && buff[1] &&
            !my_mem_cmp(buff[0], buff[1], sb[0].st_size));
}

Test(asm_core, test_2_long_file)
{
    const char *paths[] = {"tests/test_files/test2.s", NULL};
    struct stat sb[2];
    void *buff[2] = {NULL, NULL};
    int fd[2];

    if (!asm_core(paths))
        cr_assert(0);
    fd[0] = open("tests/test_files/test2.cor", O_RDONLY);
    fd[1] = open("test2.cor", O_RDONLY);
    if (fd[0] == -1 || fd[1] == -1 ||
        fstat(fd[0], sb) == -1 || fstat(fd[1], sb + 1) == -1 ||
        sb[0].st_size != sb[1].st_size)
        cr_assert(0);
    buff[0] = mmap(NULL, sb[0].st_size, PROT_READ, MAP_PRIVATE, fd[0], 0);
    buff[1] = mmap(NULL, sb[1].st_size, PROT_READ, MAP_PRIVATE, fd[1], 0);
    cr_assert(buff[0] && buff[1] &&
            !my_mem_cmp(buff[0], buff[1], sb[0].st_size));
}

Test(asm_core, test_3_multiple_file)
{
    const char *paths[] = {"tests/test_files/test3_1.s",
                    "tests/test_files/test3_2.s", NULL};
    struct stat sb[2];
    void *buff[2] = {NULL, NULL};
    int fd[2];

    if (!asm_core(paths))
        cr_assert(0);
    fd[0] = open("tests/test_files/test3.cor", O_RDONLY);
    fd[1] = open("test3_1.cor", O_RDONLY);
    if (fd[0] == -1 || fd[1] == -1 ||
        fstat(fd[0], sb) == -1 || fstat(fd[1], sb + 1) == -1 ||
        sb[0].st_size != sb[1].st_size)
        cr_assert(0);
    buff[0] = mmap(NULL, sb[0].st_size, PROT_READ, MAP_PRIVATE, fd[0], 0);
    buff[1] = mmap(NULL, sb[1].st_size, PROT_READ, MAP_PRIVATE, fd[1], 0);
    cr_assert(buff[0] && buff[1] &&
            !my_mem_cmp(buff[0], buff[1], sb[0].st_size));
}