/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update_graphic
*/

#ifndef UPDATE_GRAPHIC_H_
#define UPDATE_GRAPHIC_H_

#include "graphic.h"
#include "camera.h"
#include "win_update.h"
#include "vm.h"

sfVector2f project_iso_point(const sfVector3f pos_3d,
                            const sfVector2i map_size,
                            const sfVector2i angles);

int update_memory_3d(vm_t *vm, map_formatter_t *map, champion_t *champion);

void update_tile_map(map_formatter_t *map);

#endif /* !UPDATE_GRAPHIC_H_ */