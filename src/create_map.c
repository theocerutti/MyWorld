/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "../include/my_world.h"

sfVector2f project_iso_point(int x, int y, int z, map_t *map)
{
    sfVector2f point_2d = {0, 0};

    point_2d.x = cos(map->rotate_x * M_PI / 180) * x
    - cos(map->rotate_x * M_PI / 180) * y;
    point_2d.y = sin(map->rotate_y * M_PI / 180) * y
    + sin(map->rotate_y * M_PI / 180) * x - z;
    point_2d.x += 1920 / 2;
    point_2d.y += 1080 / 2;
    return (point_2d);
}

sfVector3f transform_3d_point(int x, int y, int z, map_t *map)
{
    sfVector2f point = project_iso_point(x, y, z, map);
    sfVector3f point_3d = {point.x, point.y, z};

    return (point_3d);
}

sfVector3f **create_2d_map(map_t *map)
{
    int x = 0;
    int y = 0;
    int z = 0;

    map->map_2d = malloc(sizeof(sfVector3f *) * (map->size.y + 1));
    for (int i = 0, j = 0; i < map->size.y; i++) {
        map->map_2d[i] = malloc(sizeof(sfVector3f) * (map->size.x + 1));
        for (j = 0; j < map->size.x; j++) {
            x = j;
            y = i;
            z = map->map_3d[i][j];
            map->map_2d[i][j] = transform_3d_point((x + map->pos.x) + map->zoom
            * j, (y + map->pos.y) + map->zoom * i, z, map);
        }
    }
    actualize_map(map);
    return (map->map_2d);
}

float perlin_noise(sfVector2f pos, perlin_noise_info_t info)
{
    float unit = info.mountain_set;
    float g[][2] = {{unit, unit}, {-unit, unit}, {unit, -unit}, {-unit, -unit},
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    sfVector2f a = {pos.x / info.resolution, pos.y / info.resolution};
    sfVector2i c = {a.x, a.y};
    sfVector2i mask = {c.x & 255, c.y & 255};
    int v0 = info.tab_noise[mask.x + info.tab_noise[mask.y]] % 8;
    int v1 = info.tab_noise[mask.x + 1 + info.tab_noise[mask.y]] % 8;
    int v2 = info.tab_noise[mask.x + info.tab_noise[mask.y + 1]] % 8;
    int v3 = info.tab_noise[mask.x + 1 + info.tab_noise[mask.y + 1]] % 8;
    float vt0 = g[v0][0] * (a.x - c.x) + g[v0][1] * (a.y - c.y);
    float vt1 = g[v1][0] * (a.x - (c.x + 1)) + g[v1][1] * (a.y - c.y);
    float vt2 = g[v2][0] * (a.x - c.x) + g[v2][1] * (a.y - (c.y + 1));
    float vt3 = g[v3][0] * (a.x - (c.x + 1)) + g[v3][1] * (a.y - (c.y + 1));
    sfVector2f temp = {a.x - c.x, a.y - c.y};
    float cx = 3 * pow(temp.x, 2) - 2 * pow(temp.x, 3);
    float cy = 3 * pow(temp.y, 2) - 2 * pow(temp.y, 3);
    sfVector2f li = {vt0 + cx * (vt1 - vt0), vt2 + cx * (vt3 - vt2)};

    return (li.x + cy * (li.y - li.x));
}

void create_3d_map(map_t *map)
{
    float z = 0;

    for (int i = 0; i < 256; i++)
        map->info_perlin.tab_noise[i] = (rand() % 255);
    map->map_3d = malloc(sizeof(int *) * map->size.y);
    map->info_perlin.resolution = map->size.x / 7;
    for (int i = 0; i < map->size.y; i++) {
        map->map_3d[i] = malloc(sizeof(int) * map->size.x);
        for (int j = 0; j < map->size.x; j++) {
            z = perlin_noise((sfVector2f){i, j},
            map->info_perlin) * map->info_perlin.alt_set;
            map->map_3d[i][j] = z;
        }
    }
    for (int i = 0; i < map->size.y; i++) {
        map->map_3d[i][0] = -100;
        map->map_3d[0][i] = -100;
        map->map_3d[map->size.y - 1][i] = -100;
        map->map_3d[i][map->size.y - 1] = -100;
    }
}
