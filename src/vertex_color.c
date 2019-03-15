/*
** EPITECH PROJECT, 2019
** color_vertex
** File description:
** color_vertex
*/

#include "../include/my_world.h"

sfColor hill_color(sfVector3f point)
{
    sfColor color = sfColor_fromRGB(107, (point.z / 200 * 255 + 100), 35);

    if (point.z / 200 * 255 + 100 < 0 || (point.z / 200 * 255 + 100) > 150)
        color.g = 137;
    return (color);
}

sfColor mountain_color(sfVector3f point)
{
    sfColor color = sfColor_fromRGB(((point.z >= 0 && point.z <= 255) ?
    point.z / 300 * 255 : 255), ((point.z >= 0 && point.z <= 255) ?
    point.z / 300 * 255 : 255), ((point.z >= 0 && point.z <= 255) ?
    point.z / 300 * 255 : 255));

    return (color);
}

sfColor water_color(sfVector3f point)
{
    sfColor color = sfColor_fromRGB(30, 300 + point.z / 100 *
    255, 300 + point.z / 100 * 255);

    return (color);
}

sfColor sand_color(sfVector3f point)
{
    sfColor color = sfColor_fromRGB(224, point.z / 125 * 255, 169);

    return (color);
}

sfColor dirt_color(sfVector3f point)
{
    sfColor color = sfColor_fromRGB(point.z / 50 * 255,
    point.z / 100 * 255 - 100, 60);

    return (color);
}