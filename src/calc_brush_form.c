/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_worldd
*/

#include "../include/my_world.h"

int check_brush_border(sfVector2i c, int k, int l, map_t *map)
{
    if (!((c.x + k) <= 0 || (c.y + l) <= 0 || (c.x + k) >= map->size.x ||
    (c.y + l) >= map->size.y))
        return (1);
    return (0);
}

int get_form_brush(sfVector2i c, sfVector2i d, brush_t *brush, map_t *map)
{
    if (check_brush_border(c, d.y, d.x, map) && sqrt(pow(d.x, 2) +
    pow(d.y, 2)) < brush->size && brush->form == CIRCLE)
        return (CIRCLE);
    if (check_brush_border(c, d.y, d.x, map) && brush->form == SQUARE)
        return (SQUARE);
    if (check_brush_border(c, d.y, d.x, map) &&
    sqrt(pow(d.x + brush->size , 2) + pow(d.y + brush->size, 2)) <
    sqrt(pow(-brush->size - brush->size, 2) + pow(-brush->size +
    brush->size, 2)) && sqrt(pow(d.x - brush->size , 2) + pow(d.y + brush->size
    , 2)) < sqrt(pow(-brush->size - brush->size, 2) + pow(-brush->size +
    brush->size, 2)) && sqrt(pow(d.x, 2) + pow(d.y - brush->size, 2)) <
    sqrt(pow(-brush->size - brush->size, 2) + pow(-brush->size -
    -brush->size, 2)) && brush->form == TRIANGLE)
        return (TRIANGLE);
    if (check_brush_border(c, d.y, d.x, map) && sqrt(pow(d.x, 2) +
    pow(d.y, 2)) < brush->size && brush->form == CONE)
        return (CONE);
    return (0);
}
