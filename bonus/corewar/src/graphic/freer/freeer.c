/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** freeer
*/

#include "free_graphic.h"

void free_ressources(win_settings_t *sets, map_formatter_t *map)
{
    free_map(map);
    free_win_settings(sets);
}