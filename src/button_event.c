/*
** EPITECH PROJECT, 2019
** button_event
** File description:
** button_event
*/

#include "../include/my_world.h"

void save_map_button_evt(data_t *data)
{
    FILE *file = NULL;
    char *str = NULL;
    char *cat = str_cat_malloc(my_itoa(data->map.size.x), "\n");

    file = fopen(str_cat_malloc("map/", data->new_map.txt), "w");
    fwrite(cat, sizeof(char), sizeof(char) * (my_strlen(cat)), file);
    for (int i = 0; i < data->map.size.x; i++) {
        for (int j = 0; j < data->map.size.x; j++) {
            str = my_itoa(data->map.map_3d[i][j]);
            fwrite(str, sizeof(char), sizeof(char) *
            (my_strlen(str)), file);
            fwrite(",", sizeof(char), sizeof(char), file);
        }
        fwrite("\n", sizeof(char), sizeof(char), file);
    }
}

void move_button_evt(data_t *data, sfVector2i pos_mouse,
sfVector2i pos_mouse_last)
{
    int x_move = pos_mouse.x - pos_mouse_last.x;
    int y_move = pos_mouse.y - pos_mouse_last.y;

    if (isKeyPressed(sfKeyLControl)) {
        x_move *= 2;
        y_move *= 2;
    }
    move_map(&data->map, x_move, y_move);
}

void brush_evt(data_t *d, sfRenderWindow *window)
{
    all_brush(window, d);
    if (isKeyPressed(sfKeyW))
            d->brush.size += 1;
    if (isKeyPressed(sfKeyX)) {
            d->brush.size -= 0.5;
    }
    if (isKeyPressed(sfKeyC))
        if (d->brush.hardness < 100)
            d->brush.hardness += 1;
    if (isKeyPressed(sfKeyV)) {
        if (d->brush.hardness > -100)
            d->brush.hardness -= 1;
    }
}

void move_screen_border_evt(data_t *d, sfVector2i pos_mouse)
{
    int v_move = 5;

    if (isKeyPressed(sfKeyLeft) || isKeyPressed(sfKeyQ) || (pos_mouse.x < 20
    && pos_mouse.x > 0 && pos_mouse.y > 0 && pos_mouse.y < 1080))
        move_map(&d->map, v_move, -v_move);
    if (isKeyPressed(sfKeyRight) || isKeyPressed(sfKeyD) || (pos_mouse.x >
    1900 && pos_mouse.x < 1980 && pos_mouse.y > 0 && pos_mouse.y < 1080))
        move_map(&d->map, -v_move, v_move);
    if (isKeyPressed(sfKeyUp) || isKeyPressed(sfKeyZ) || (pos_mouse.y < 20 &&
    pos_mouse.y > 0 && pos_mouse.x > 0 && pos_mouse.x < 1920))
        move_map(&d->map, v_move, v_move);
    if (isKeyPressed(sfKeyDown) || isKeyPressed(sfKeyS) || (pos_mouse.y >
    1000 && pos_mouse.y < 1080 && pos_mouse.x > 0 && pos_mouse.x < 1920))
        move_map(&d->map, -v_move, -v_move);
}
