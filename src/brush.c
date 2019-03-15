/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "../include/my_world.h"

void apply_effect(int type, data_t *d, int k, int l)
{
    sfVector2i c = {d->brush.middle_point.x, d->brush.middle_point.y};

    if (type == 0)
        d->map.map_3d[c.x + k][c.y + l] += d->brush.hardness;
    else
        d->map.map_3d[c.x + k][c.y + l] = d->brush.hight;
}

void brush_type(data_t *d, int type)
{
    sfVector2i c = {d->brush.middle_point.x, d->brush.middle_point.y};

    for (int k = -d->brush.size; k < d->brush.size; k++) {
        for (int l = -d->brush.size; l < d->brush.size; l++) {
            if (get_form_brush(c, (sfVector2i){l, k}, &d->brush, &d->map)) {
                apply_effect(type, d, k, l);
                d->map.map_2d[c.x + k][c.y + l] = transform_3d_point((
                c.y + l + d->map.pos.x) + d->map.zoom * (c.y + l),
                (c.x + k + d->map.pos.y) + d->map.zoom * (c.x + k),
                d->map.map_3d[c.x + k][c.y + l], &d->map);
            }
        }
    }
    if (d->brush.form == CONE && type == 0)
        d->brush.size += 0.5;
}

void all_brush_next(data_t *d)
{
    if (isButtonPressed(sfMouseRight) && !isKeyPressed(sfKeyLControl)) {
        d->brush.hardness *= -1;
        if (d->brush.middle_point.x > 0 && d->brush.middle_point.y > 0)
            brush_type(d, 0);
        actualize_map(&d->map);
        d->brush.hardness *= -1;
    }
}

void all_brush(sfRenderWindow *window, data_t *d)
{
    d->brush.mouse = sfMouse_getPositionRenderWindow(window);
    if (isButtonPressed(sfMouseLeft) && isKeyPressed(sfKeyLControl) &&
    !isButtonPressed(sfMouseRight)) {
        if (d->brush.middle_point.x > 0 && d->brush.middle_point.y > 0)
            brush_type(d, 1);
        actualize_map(&d->map);
    }
    if (isButtonPressed(sfMouseLeft) && !isKeyPressed(sfKeyLControl)) {
        if (d->brush.middle_point.x > 0 && d->brush.middle_point.y > 0)
            brush_type(d, 0);
        actualize_map(&d->map);
    }
    all_brush_next(d);
}
