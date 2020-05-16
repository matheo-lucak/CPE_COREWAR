/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** win
*/

/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Updates the window settings.
*/

#include "my.h"
#include "win_update.h"
#include "vector_engine.h"

static void update_window_anchor(win_settings_t *sets)
{
    sets->anchor.topleft = sfRenderWindow_mapPixelToCoords(sets->window,
                                            VEC2I(0, 0),
                                            sets->view);
    sets->anchor.topright = sfRenderWindow_mapPixelToCoords(sets->window,
                                            VEC2I(sets->size.x, 0),
                                            sets->view);
    sets->anchor.bottomleft = sfRenderWindow_mapPixelToCoords(sets->window,
                                            VEC2I(0, sets->size.y),
                                            sets->view);
    sets->anchor.bottomright = sfRenderWindow_mapPixelToCoords(sets->window,
                                            VEC2I(sets->size.x, sets->size.y),
                                            sets->view);
}

static void update_window_scale(win_settings_t *sets)
{
    sfVector2f view_size = sfView_getSize(sets->view);

    sets->scale.x = view_size.x / sets->size.x;
    sets->scale.y = view_size.y / sets->size.y;
}

void update_window_settings(win_settings_t *sets)
{
    sfVector2u size_u;

    if (!sets)
        return ;
    size_u = sfRenderWindow_getSize(sets->window);
    sets->size = (sfVector2f){size_u.x, size_u.y};
    update_window_scale(sets);
    update_window_anchor(sets);
    update_mouse_tool(sets);
}