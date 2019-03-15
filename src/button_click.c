/*
** EPITECH PROJECT, 2019
** button_click
** File description:
** button_click
*/

#include "../include/my_world.h"

void button_click_evt2(data_t *d, sfVector2i pos_mouse,
sfVector2i pos_mouse_last, sfRenderWindow *window)
{
    if ((d->selecting_tool == CLEAR_MAP && isButtonPressed(sfMouseLeft))
    || isKeyPressed(sfKeyN))
        clear_map(&d->map);
    if (d->selecting_tool == MOVE && isButtonPressed(sfMouseLeft)) {
        move_button_evt(d, pos_mouse, pos_mouse_last);
    }
    if (d->selecting_tool == BRUSH)
        brush_evt(d, window);
    if (d->selecting_tool != MOVE) {
        move_screen_border_evt(d, pos_mouse);
    }
    if (isKeyPressed(sfKeyI))
        rotate_vertical(&d->map, 1, 1);
    else if (isKeyPressed(sfKeyK))
        rotate_vertical(&d->map, -1, -1);
    if (isKeyPressed(sfKeySpace))
        center_map(&d->map);
}

void button_click_evt1(data_t *d, sfEvent event, sfVector2i pos_mouse)
{
    if (isKeyPressed(sfKeyL) && event.type == sfEvtKeyPressed) {
        rotate_side(&d->map, LEFT);
        rotate_side(&d->map, RIGHT);
    }
    if (d->selecting_tool == ZOOM && event.type == sfEvtMouseButtonPressed) {
        if (isButtonPressed(sfMouseRight))
            zoom_map(&d->map, -1);
        else if (isButtonPressed(sfMouseLeft))
            zoom_map(&d->map, 1);
    }
    if (isKeyPressed(sfKeyM) || (d->selecting_tool == REGEN &&
    event.type == sfEvtMouseButtonPressed)) {
        create_3d_map(&d->map);
        free_2d_map(&d->map);
        create_2d_map(&d->map);
    }
    if (is_clicked(&d->ui.button[4], pos_mouse)
    && event.type == sfEvtMouseButtonPressed) {
        save_map_button_evt(d);
    }
}

void button_click_evt3(data_t *d, sfEvent event, sfRenderWindow *window,
sfVector2i pos_mouse)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseWheelMoved)
        zoom_map(&d->map, event.mouseWheel.delta);
    if (isKeyPressed(sfKeyJ) && event.type == sfEvtKeyPressed) {
        rotate_side(&d->map, RIGHT);
        rotate_side(&d->map, LEFT);
    }
    if (is_clicked(&d->ui.dd_brush_form.button[0], pos_mouse)
    && event.type == sfEvtMouseButtonPressed)
        d->ui.dd_brush_form.is_clicked =
        (d->ui.dd_brush_form.is_clicked == 0) ? 1 : 0;
}