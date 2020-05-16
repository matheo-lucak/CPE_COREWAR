/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** camera
*/

#ifndef CAMERA_H_
#define CAMERA_H_

#include "graphic.h"

sfBool center_cam(win_settings_t *sets, map_formatter_t *map);

sfBool control_camera_view(win_settings_t sets, presets_t map_settings);
sfBool control_angle_view(presets_t *map_settings);

sfVector2f transl_up(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_down(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_left(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_right(const sfVector2i mv_speed, const sfVector2f coeff);

void rotate_right(presets_t *map_settings, sfBool *changed);
void rotate_left(presets_t *map_settings, sfBool *changed);
void rotate_down(presets_t *map_settings, sfBool *changed);
void rotate_up(presets_t *map_settings, sfBool *changed);

#endif /* !CAMERA_H_ */