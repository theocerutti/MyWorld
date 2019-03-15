/*
** EPITECH PROJECT, 2019
** display2
** File description:
** display2
*/

#include "../include/my_world.h"

void actualize_map(map_t *map)
{
    sfVertexArray_clear(map->vertex_array);
    sfVertexArray_setPrimitiveType(map->vertex_array, sfQuads);
    for (int i = 0; i < map->size.y - 1; i++) {
        for (int j = 0; j < map->size.x - 1; j++) {
            add_quads_good(i, j, map);
        }
    }
}