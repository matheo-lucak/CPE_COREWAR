/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_win
*/

#include "free_graphic.h"

void free_win_settings(win_settings_t sets)
{
    if (sets.view)
        sfView_destroy(sets.view);
    if (sets.window) {
        if (sfRenderWindow_isOpen(sets.window))
            sfRenderWindow_close(sets.window);
        sfRenderWindow_destroy(sets.window);
    }
}