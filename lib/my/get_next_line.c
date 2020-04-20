/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** gets the next line of a file
*/

#include <stdlib.h>
#include <unistd.h>

static char *my_strdup(char *template, const char end)
{
    char *dup = NULL;
    int len_template = -1;
    int i = -1;

    if (!template)
        return (NULL);
    while (template[++len_template] != end && template[len_template]);
    dup = malloc(sizeof(char) * (len_template + 1));
    if (!dup)
        return (NULL);
    while (++i < len_template)
        dup[i] = template[i];
    dup[i] = '\0';
    return (dup);
}

static char *my_strcat(char *first, char *second)
{
    char *result = NULL;
    int count_tmp = -1;
    int count_res = -1;

    if (!first || !second)
        return (!first) ? my_strdup(second, '\0') : my_strdup(first, '\0');
    while (first[++count_tmp]);
    while (second[++count_res]);
    result = malloc(sizeof(char) * (count_tmp + count_res + 1));
    if (!result)
        return (NULL);
    count_tmp = 0;
    count_res = 0;
    while (first[count_tmp])
        result[count_res++] = first[count_tmp++];
    count_tmp = 0;
    while (second[count_tmp])
        result[count_res++] = second[count_tmp++];
    result[count_res] = '\0';
    return (result);
}

static char *get_line(const int fd, char **res, int *i, const int nb_bytes)
{
    static char *tmp = NULL;
    static int size = 0;

    tmp = malloc(sizeof(char) * (nb_bytes + 1));
    if (!tmp)
        return (NULL);
    size = read(fd, tmp, nb_bytes);
    if (size <= 0)
        return (my_strdup((*res), '\n'));
    tmp[size] = '\0';
    (*res) = my_strcat((*res), tmp);
    if (!(*res))
        return (NULL);
    if (tmp && tmp != (*res))
        free(tmp);
    while ((*res)[(*i)] && (*res)[(*i)] != '\n')
        (*i) += 1;
    if ((*res)[(*i)] != '\n')
        get_line(fd, res, i, nb_bytes);
    return (my_strdup((*res), '\n'));
}

static int check_stock_saved_line(char **res, char **line,
                                    char **stock)
{
    int index = 0;

    if (!(*stock) || (*stock)[0] == '\0')
        return (0);
    (*res) = my_strdup((*stock), '\0');
    while ((*stock)[index] && (*stock)[index] != '\n')
        index += 1;
    if ((*stock)[index] == '\n') {
        (*line) = my_strdup((*res), '\n');
        (*stock) = my_strdup(&(*res)[index + 1], '\0');
        return (1);
    } else
        free((*stock));
    return (0);
}

char *get_next_line(const int fd, const size_t nb_bytes)
{
    static char *stock = NULL;
    char *line = NULL;
    char *res = NULL;
    int index = 0;

    if (fd == -1 || !nb_bytes)
        return (NULL);
    if (check_stock_saved_line(&res, &line, &stock) == 1)
        return (line);
    line = get_line(fd, &res, &index, nb_bytes);
    if (res) {
        stock = index > 0 ? my_strdup(&res[index + 1], '\0') : NULL;
        free(res);
    }
    return (line);
}