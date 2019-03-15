/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include "../include/my_world.h"

void clicked_opacity_button_tab(button_t *button, sfVector2i opt,
sfVector2i pos_mouse, int plus)
{
    sfColor color_full = {255, 255, 255, 255};
    sfColor color_normal = {255, 255, 255, 150};

    if ((is_clicked(&button[opt.y], pos_mouse) && opt.y != 0 &&
    plus == 1) || (is_clicked(&button[opt.y], pos_mouse)
    && plus == 0)) {
        for (int i = plus; i < opt.x; i++) {
            if (i != opt.y)
                button[i].is_clicked = 0;
            sfSprite_setColor(button[i].s, color_normal);
        }
        button[opt.y].is_clicked = (button[opt.y].is_clicked == 0) ? 1 : 0;
        if (button[opt.y].is_clicked == 1) {
            sfSprite_setColor(button[opt.y].s, color_full);
        } else {
            sfSprite_setColor(button[opt.y].s, color_normal);
        }
    }
}

void select_button(data_t *d, sfVector2i pos_mouse, int button)
{
    clicked_opacity_button_tab(d->ui.button, (sfVector2i){d->ui.nb_button,
    button}, pos_mouse, 0);
    if (is_clicked(&d->ui.button[button], pos_mouse)) {
        if (d->ui.button[button].is_clicked)
            d->selecting_tool = d->ui.button[button].id;
        else
            d->selecting_tool = BRUSH;
    }
}

void select_button_dropdown_form(data_t *d, sfVector2i pos_mouse, int button)
{
    clicked_opacity_button_tab(d->ui.dd_brush_form.button,
    (sfVector2i){d->ui.dd_brush_form.nb_button, button}, pos_mouse, 1);
    if (is_clicked(&d->ui.dd_brush_form.button[button], pos_mouse)) {
        d->brush.form = d->ui.dd_brush_form.button[button].id;
    }
}

void get_event(sfRenderWindow *window, data_t *d)
{
    static sfVector2i pos_mouse_last = {0, 0};
    sfEvent event = {0};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        for (int button = 0; button < d->ui.nb_button; button++)
            select_button(d, pos_mouse, button);
        for (int i = 0; i < d->ui.dd_brush_form.nb_button; i++)
            if (event.type == sfEvtMouseButtonPressed)
                select_button_dropdown_form(d, pos_mouse, i);
        hover_all_button(&d->ui, pos_mouse);
        button_click_evt3(d, event, window, pos_mouse);
        button_click_evt1(d, event, pos_mouse);
    }
    button_click_evt2(d, pos_mouse, pos_mouse_last, window);
    pos_mouse_last = sfMouse_getPositionRenderWindow(window);
}
