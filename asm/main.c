/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** Takes a champion in parameter and generates an asm file from it.
*/

#include "my.h"
#include "asm_usage.h"

int main(const int ac, const char **av,
        __attribute__((unused))const char **env)
{
    if (ac != 2 || !av || !av[0]) {
        print_asm_usage();
        return (84);
    }
    if (my_str_eq_str(av[1], "-h"))
        return (print_asm_usage()) ? 0 : 84;
    return (0);
}