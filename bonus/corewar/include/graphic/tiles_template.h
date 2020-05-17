/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tiles_template
*/

#ifndef TILES_TEMPLATE_H_
#define TILES_TEMPLATE_H_

#include "update_graphic.h"
#include "vector_engine.h"

static const sfVector3f corner_offset[3][4] =
{
    {
        VEC3F(1, 1, 0),
        VEC3F(0, 1, 0),
        VEC3F(0, 1, 1),
        VEC3F(1, 1, 1)
    },
    {
        VEC3F(1, 1, 0),
        VEC3F(1, 1, 1),
        VEC3F(1, 0, 1),
        VEC3F(1, 0, 0)
    },
    {
        VEC3F(1, 1, 1),
        VEC3F(0, 1, 1),
        VEC3F(0, 0, 1),
        VEC3F(1, 0, 1)
    }
};

static inline sfVector2f compute_vertex_pos(sfVector3f point,
                                            presets_t map_sets,
                                        size_t side, size_t index)
{
    return (project_iso_point(VEC3F(
                point.x + corner_offset[side][index].x,
                point.y + corner_offset[side][index].y,
                point.z * corner_offset[side][index].z),
                map_sets.size, map_sets.angles));
}

#endif /* !TILES_TEMPLATE_H_ */
