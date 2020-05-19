/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_win
*/

#include "my.h"
#include "vector_engine.h"
#include "init_graphic.h"

void update_window_settings(win_settings_t *sets);

static bool init_win_view(win_settings_t *sets)
{
    sets->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (!sets->view)
        return (false);
    sfView_setCenter(sets->view, VEC2F(0, 0));
    return (true);
}

bool init_win_settings(win_settings_t *sets)
{
    if (!sets)
        return (false);
    my_memset((char *)sets, 0, sizeof(win_settings_t));
    sets->video_mode = (sfVideoMode){1920, 1080, 32};
    sets->window = sfRenderWindow_create(sets->video_mode,
                        "Corewar by Dorian truchon & Malo Couaran &"
                        "Guillaume Bogard-Coquard & Matheo Lucak",
                        sfClose | sfDefaultStyle, NULL);
    if (!sets->window)
        return (false);
    sfRenderWindow_setFramerateLimit(sets->window, 60);
    sfRenderWindow_setMouseCursorVisible(sets->window, true);
    if (!init_win_view(sets))
        return (false);
    my_memset(&(sets->mouse_tool), sizeof(mouse_tool_t), 0);
    update_window_settings(sets);
    return (true);
}