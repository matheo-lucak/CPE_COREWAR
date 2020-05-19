/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_mem_cmp
*/

#include "my.h"

static int my_mem_cmp_error(void *buff1, void *buff2)
{
    if (!buff1 && !buff2)
        return (0);
    if (!buff1)
        return (1);
    if (!buff2)
        return (-1);
    return (0);
}

int my_mem_cmp(void *buff1, void *buff2, size_t n)
{
    register size_t index = 0;

    if (!buff1 || !buff2)
        return (my_mem_cmp_error(buff1, buff2));
    for (; index < n && buff1 && buff2; index += 1) {
        if (((char *)buff1)[index] > ((char *)buff2)[index])
            return (1);
        else if (((char *)buff1)[index] < ((char *)buff2)[index])
            return (-1);
    }
    return (0);
}
