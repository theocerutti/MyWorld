/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "../include/my_world.h"

void color_vertex_brush_preview(map_t *map, sfVector2i mid,
sfVertexArray *vertex_array, sfVector2i vec)
{
    sfColor color = {110, 11, 20, 255};
    unsigned long index = 0;
    sfVertex *vertex = NULL;

    for (int point = 0; point < 4; point++) {
        vertex = NULL;
        index = point + (((mid.x) * (map->size.y)) * 4 -
        ((mid.x) * 4) + (mid.y) * 4 -
        map->size.y * 4 + vec.x * 4 * map->size.y - vec.x * 4 + vec.y * 4);
        if (index > 0 && index <
        sfVertexArray_getVertexCount(vertex_array) - 1) {
            vertex = sfVertexArray_getVertex(vertex_array, index);
            vertex->color = color;
        }
    }
}

void b_dis(sfRenderWindow *window, map_t *map, brush_t *brush, sfVector2i mid)
{
    sfVertexArray *vertex_array = sfVertexArray_copy(map->vertex_array);

    for (int k = -brush->size; k < brush->size + 1; k++) {
        for (int l = -brush->size; l < brush->size + 1; l++) {
            if (get_form_brush(mid, (sfVector2i){k, l}, brush, map)) {
                color_vertex_brush_preview(map, mid, vertex_array,
                (sfVector2i){l, k});
            }
        }
    }
    sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void dis_brush_next(sfRenderWindow *window, map_t *map, brush_t *brush, int *a)
{
    if (isKeyPressed(sfKeyLControl) && !isButtonPressed(sfMouseLeft)
    && brush->middle_point.x > -1 && brush->middle_point.y > -1)
        brush->hight = map->map_3d[brush->middle_point.x]
        [brush->middle_point.y];
    if (brush->middle_point.x > 0 && brush->middle_point.y > 0 && *a == 1) {
        b_dis(window, map, brush, brush->middle_point);
    }
    else
        sfRenderWindow_drawVertexArray(window, map->vertex_array, NULL);
}

int display_lock_brush(int *activate, sfRenderWindow *window, map_t *map,
brush_t *brush)
{
    if (isKeyPressed(sfKeyLShift) && *activate != -1 &&
    brush->middle_point.x > 0 && brush->middle_point.y > 0) {
        b_dis(window, map, brush, brush->middle_point);
        return (1);
    }
    *activate = -1;
    brush->middle_point.x = -1;
    brush->middle_point.y = -1;
    return (0);
}

void display_brush_preview(sfRenderWindow *window, map_t *map, brush_t *brush)
{
    sfVector3f vec = {0};
    static int activate = -1;

    if (display_lock_brush(&activate, window, map, brush))
        return;
    for (int i = 0; i < map->size.y; i++)
        for (int j = 0; j < map->size.x; j++) {
            vec = transform_3d_point((j + map->pos.x) + map->zoom * j,
            (i + map->pos.y) + map->zoom * i, map->map_3d[i][j], map);
            if (sqrt(pow(vec.x - brush->mouse.x, 2) + \
            pow(vec.y - brush->mouse.y, 2)) <= map->zoom * 2) {
                brush->middle_point.x = i;
                brush->middle_point.y = j;
                activate = 1;
            }
        }
    dis_brush_next(window, map, brush, &activate);
}
