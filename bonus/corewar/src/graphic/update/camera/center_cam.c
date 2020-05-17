/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** center_cam
*/

#include "camera.h"
#include "vector_engine.h"

static sfBool is_outside_view(win_settings_t *sets, sfVector2f **map,
                                                        sfVector2i size)
{
    sfFloatRect window_area = {0, 0, sets->size.x, sets->size.y};
    sfVector2i tmp_point = {0, 0};

    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[0][0], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[size.y][0], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[0][size.x], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                        map[size.y][size.x], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    return (sfTrue);
}

sfBool center_cam(win_settings_t *sets, map_formatter_t *map)
{
    sfVector2f center = {0, 0};
    sfVector2i size = map->map_settings.size;

    if (!sfKeyboard_isKeyPressed(sfKeyC))
        return (sfFalse);
    size = VEC2I(size.x - 1, size.y - 1);
    if (size.x < 0 || size.y < 0)
        return (sfFalse);
    center.x = (map->map_2d[size.y][size.x].x + map->map_2d[0][0].x) / 2;
    center.y = (map->map_2d[size.y][size.x].y + map->map_2d[0][0].y) / 2;
    sfView_setCenter(sets->view, center);
    while (!is_outside_view(sets, map->map_2d, size))
        sfView_zoom(sets->view, 1.001);
    do {
        sfView_zoom(sets->view, 0.999);
    } while (is_outside_view(sets, map->map_2d, size));
    return (sfTrue);
}