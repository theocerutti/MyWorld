/*
** EPITECH PROJECT, 2019
** vertex2
** File description:
** vertex2
*/

#include "../include/my_world.h"

void add_quads_good(int i, int j, map_t *map)
{
    sfVector3f point[4] = {0};
    sfColor color[4] = {0};
    sfColor border_color = sfColor_fromRGB(149, 148, 139);

    point[0] = map->map_2d[i][j];
    point[1] = map->map_2d[i][j + 1];
    point[2] = map->map_2d[i + 1][j + 1];
    point[3] = map->map_2d[i + 1][j];
    update_alt(point, map->alt);
    update_color(color, point);
    if (j == 0 || i == 0 || i > map->size.x - 3 || j > map->size.x - 3) {
        for (int i = 0; i < 4; i++)
            color[i] = border_color;
        add_quads(map, color, point);
    } else
        add_quads(map, color, point);
}