/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void center_map(map_t *map)
{
    map->pos.x = -((map->size.x * map->zoom) / 2);
    map->pos.y = -((map->size.y * map->zoom) / 2);
    free_2d_map(map);
    create_2d_map(map);
}