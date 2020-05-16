/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** graphic
*/

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct presets_s {
    sfVector2i size;
    sfVector2i angles;
    sfVector2i rotation_speed;
    sfVector2i movement_speed;
} presets_t;

typedef struct map_formatter_s {
    presets_t map_settings;
    float **map_3d;
    sfVector2f **map_2d;
    sfVertexArray ***tiles;
} map_formatter_t;

typedef struct mouse_tool_s {
    sfVector2f pos;
    sfVector2f click_pos;
    sfBool hold;
    sfBool click;
} mouse_tool_t;

typedef struct anchor_s {
    sfVector2f topleft;
    sfVector2f topright;
    sfVector2f bottomleft;
    sfVector2f bottomright;
} anchor_t;

typedef struct win_settings_s {
    sfRenderWindow *window;
    sfView *view;
    anchor_t anchor;
    sfVector2f size;
    sfVector2f scale;
    sfVideoMode video_mode;
    sfEvent event;
    mouse_tool_t mouse_tool;
} win_settings_t;

bool init_win_settings(win_settings_t *sets);

bool init_map(map_formatter_t *map);

void draw_tile_map(win_settings_t *sets, map_formatter_t *map);

#endif /* !GRAPHIC_H_ */