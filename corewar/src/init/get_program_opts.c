/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_program_opts.c
*/

#include <stdbool.h>
#include "my.h"
#include "program.h"

static bool check_n_str(char *str)
{
    int i = -1;

    if (!str)
        return false;
    while (str[++i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

static bool check_a_str(char *str)
{
    int i = -1;

    if (!str)
        return false;
    while (str[++i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

static int check_opt_n(char *str, int *index, program_t *program, bool *found_n)
{
    if (!str || !index)
        return 84;
    if (*found_n == true || check_n_str(str) == false)
        return 84;
    *found_n = true;
    program->id = my_atoi(str);
    return 0;
}

static int check_opt_a(char *str, int *index, program_t *program, bool *found_a)
{
    if (!str || !index)
        return 84;
    if (*found_a == true || check_a_str(str) == false)
        return 84;
    *found_a = true;
    program->load_address = my_atoi(str);
    return 0;
}

int get_program_opts(int ac, char **av, int *index, program_t *program)
{
    bool found_n = false;
    bool found_a = false;

    if (!program || !av || !index)
        return 84;
    while (++*index < ac && av[*index][0] == '-') {
        if (!my_strcmp(av[*index], "-n") &&
            check_opt_n(av[*index + 1], index, program, &found_n) == 84)
            return 84;
        if (!my_strcmp(av[*index], "-a") &&
            check_opt_a(av[*index + 1], index, program, &found_a) == 84)
            return 84;
        if (av[*index][0] == '-')
            ++*index;
    }
    return 0;
}