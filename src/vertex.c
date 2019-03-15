/*
** EPITECH PROJECT, 2019
** vertex
** File description:
** vertex
*/

#include "../include/my_world.h"

sfVertex append_vertex_map(sfVertexArray *vertex_array,
sfColor color, sfVector3f point)
{
    sfVertex vertex = {0};
    sfVector2f pos = {point.x, point.y};

    vertex.color = color;
    vertex.position = pos;
    sfVertexArray_append(vertex_array, vertex);
    return (vertex);
}

void add_quads(map_t *map, sfColor color[4], sfVector3f point[4])
{
    append_vertex_map(map->vertex_array, color[0], point[0]);
    append_vertex_map(map->vertex_array, color[1], point[1]);
    append_vertex_map(map->vertex_array, color[2], point[2]);
    append_vertex_map(map->vertex_array, color[3], point[3]);
}

void update_alt(sfVector3f point[4], sfVector2i alt)
{
    point[0].z = (point[0].z > alt.x) ? alt.x : point[0].z;
    point[1].z = (point[1].z > alt.x) ? alt.x : point[1].z;
    point[2].z = (point[2].z > alt.x) ? alt.x : point[2].z;
    point[3].z = (point[3].z > alt.x) ? alt.x : point[3].z;
    point[0].z = (point[0].z < alt.y) ? alt.y : point[0].z;
    point[1].z = (point[1].z < alt.y) ? alt.y : point[1].z;
    point[2].z = (point[2].z < alt.y) ? alt.y : point[2].z;
    point[3].z = (point[3].z < alt.y) ? alt.y : point[3].z;
}

sfVector3f calc_mid_point(sfVector3f point[4])
{
    sfVector3f mid;

    mid.x = (point[0].x + point[1].x + point[2].x + point[3].x) / 4;
    mid.y = (point[0].y + point[1].y + point[2].y + point[3].y) / 4;
    mid.z = (point[0].z + point[1].z + point[2].z + point[3].z) / 4;
    return (mid);
}

void update_color(sfColor color[4], sfVector3f point[4])
{
    sfVector3f mid = calc_mid_point(point);

    if (mid.z >= 100)
        for (int i = 0; i < 4; i++)
            color[i] = mountain_color(point[i]);
    if (mid.z >= -20 && mid.z < 100)
        for (int i = 0; i < 4; i++)
            color[i] = hill_color(point[i]);
    if (mid.z >= -30 && mid.z < -20)
        for (int i = 0; i < 4; i++)
            color[i] = dirt_color(point[i]);
    if (mid.z >= -40 && mid.z < -30)
        for (int i = 0; i < 4; i++)
            color[i] = sand_color(point[i]);
    if (mid.z < -40)
        for (int i = 0; i < 4; i++)
            color[i] = water_color(point[i]);
}