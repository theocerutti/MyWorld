/*
** EPITECH PROJECT, 2019
** button
** File description:
** button
*/

#include "../include/my_world.h"

int is_clicked(button_t *obj, sfVector2i pos_mouse)
{
    if (isButtonPressed(sfMouseLeft) && is_contain(*obj, pos_mouse)) {
        return (1);
    }
    return (0);
}

int is_contain(button_t obj, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= obj.pos.x &&
    pos_mouse.x <= obj.pos.x + obj.rect.width
    && pos_mouse.y >= obj.pos.y &&
    pos_mouse.y <= obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}

void hover_button(button_t *button, sfVector2i pos_mouse)
{
    sfColor color_hover = {255, 255, 255, 255};
    sfColor color_normal = {255, 255, 255, 150};

    if (button->is_clicked == 0)
        sfSprite_setColor(button->s, color_normal);
    if (is_contain(*button, pos_mouse))
        sfSprite_setColor(button->s, color_hover);
}

void hover_all_button(ui_t *ui, sfVector2i pos_mouse)
{
    sfColor color_hover = {255, 255, 255, 255};
    sfColor color_normal = {255, 255, 255, 150};

    for (int i = 0; i < ui->nb_button; i++)
        hover_button(&ui->button[i], pos_mouse);
    sfSprite_setColor(ui->dd_brush_form.button[0].s, color_normal);
    if (is_contain(ui->dd_brush_form.button[0], pos_mouse))
        sfSprite_setColor(ui->dd_brush_form.button[0].s, color_hover);
}