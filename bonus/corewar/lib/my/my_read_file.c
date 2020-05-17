/*
** EPITECH PROJECT, 2019
** navy
** File description:
** get_maps.c
*/

#include <fcntl.h>
#include <stdio.h>

char **my_realloc_tab(void **tab, size_t tab_size, size_t dest_size);

char **my_read_file(const char *path)
{
    FILE *fd = fopen(path, "r");
    char **dest = NULL;
    char *line = NULL;
    size_t read_size = 0;
    size_t i = 0;

    if (fd == NULL)
        return NULL;
    while (getline(&line, &read_size, fd) > 0) {
        dest = my_realloc_tab((void **)dest, sizeof(char *) * i,
                sizeof(char *) * (i + 2));
        if (!dest)
            return NULL;
        dest[i] = line;
        line = NULL;
        ++i;
    }
    return dest;
}