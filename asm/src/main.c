/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** Takes a champion in parameter and generates an asm file from it.
*/

#include "my.h"
#include "usage.h"
#include "asm.h"

static void print_usage(const char *bin_name)
{
    if (bin_name)
        my_printf(asm_usage, bin_name);
}

static bool should_print_usage(const int ac, const char *av[])
{
    register int index = 0;
    char *help_template[] = {"-h", "--help", NULL};

    for (index = 0; index < ac; index += 1) {
        if (my_mass_strcmp((char *)av[index], help_template) != -1)
            return (true);
    }
    return (false);
}

#include "parser.h"

int main(__attribute__((unused))const int ac,
        __attribute__((unused))const char *av[],
        __attribute__((unused))const char **env)
{
        char line[] = "label: ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    redirect_body(reader_i, &asm_i);
    link_labels(asm_i.labels, asm_i.instructs);
    if (ac != 2)
        return (84);
    if (should_print_usage(ac, av)) {
        print_usage(av[0]);
        return (84);
    }
    return (asm_core(av + 1) ? 0 : 84);
}