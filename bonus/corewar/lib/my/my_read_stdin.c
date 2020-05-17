/*
** EPITECH PROJECT, 2019
** navy
** File description:
** get_maps.c
*/

#include <stdio.h>

char **my_realloc_tab(void *tab, size_t tab_size, size_t dest_size);

void *my_sfree(void *ptr);

int my_read_stdin(char ***file)
{
    char *line = NULL;
    size_t read_size = 0;
    size_t i = 0;
    int exit = 0;

    if (!file)
        return 84;
    while ((exit = getline(&line, &read_size, stdin)) > 0) {
        *file = my_realloc_tab((void *)*file, sizeof(char *) * i,
                sizeof(char *) * (i + 2));
        if (!*file)
            return 84;
        if (line[exit - 1] == '\n')
            line[exit - 1] = '\0';
        (*file)[i] = line;
        line = NULL;
        ++i;
    }
    my_sfree(line);
    return 0;
}