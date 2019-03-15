/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void clear_map(map_t *map)
{
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            map->map_3d[i][j] = 0;
        }
    }
    for (int i = 0; i < map->size.y; i++) {
        map->map_3d[i][0] = -100;
        map->map_3d[0][i] = -100;
        map->map_3d[map->size.y - 1][i] = -100;
        map->map_3d[i][map->size.y - 1] = -100;
    }
    free_2d_map(map);
    create_2d_map(map);
}

void zoom_map(map_t *map, int delta)
{
    if (map->zoom <= 0)
        map->zoom = 1;
    if (map->zoom >= 100)
        map->zoom = 100;
    map->zoom += delta;
    free_2d_map(map);
    create_2d_map(map);
}

void move_map(map_t *map, int x_off, int y_off)
{
    map->pos.x += x_off;
    map->pos.y += y_off;
    free_2d_map(map);
    create_2d_map(map);
}

void rotate_vertical(map_t *map, float rotate_x, float rotate_y)
{
    if ((map->rotate_x + rotate_x > 0 && map->rotate_x + rotate_x < 50)
    && (map->rotate_y + rotate_y > 0 && map->rotate_y + rotate_y < 50)) {
        map->rotate_x += rotate_x;
        map->rotate_y += rotate_y;
    }
    free_2d_map(map);
    create_2d_map(map);
}

void rotate_side(map_t *map, int rotate_state)
{
    int **new_map = NULL;

    new_map = malloc(sizeof(int *) * map->size.x);
    for (int i = 0; i < map->size.x; i++)
        new_map[i] = malloc(sizeof(int) * map->size.y);
    if (rotate_state == LEFT) {
        for (int i = 0; i < map->size.y; i++) {
            for (int j = 0; j < map->size.x; j++) {
                new_map[j][i] = map->map_3d[i][j];
            }
        }
    } else {
        for (int i = map->size.y - 1, k = 0; i >= 0; i--, k++)
            new_map[k] = map->map_3d[i];
    }
    map->map_3d = new_map;
    free_2d_map(map);
    create_2d_map(map);
    actualize_map(map);
}
