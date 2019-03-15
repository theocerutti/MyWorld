/*
** EPITECH PROJECT, 2019
** init_data
** File description:
** init_data
*/

#include "../include/my_world.h"

void init_ui3(ui_t *ui)
{
    button_t b_zoom = {0, 0, {64, 64}, {0}, {20, 450}, {0, 0}, 150, ZOOM, 0};
    button_t cls = {0, 0, {64, 64}, {0}, {20, 530}, {0, 0}, 150, CLEAR_MAP, 0};
    button_t b_regen = {0, 0, {64, 64}, {0}, {20, 610}, {0, 0}, 150, REGEN, 0};
    button_t b_save = {0, 0, {64, 64}, {0}, {20, 770}, {0, 0}, 150, SAVE, 0};

    init_obj_ui(&b_zoom, "assets/images/zoom_button.png");
    init_obj_ui(&cls, "assets/images/erase_map_button.png");
    init_obj_ui(&b_regen, "assets/images/regen_map_button.png");
    init_obj_ui(&b_save, "assets/images/save_button.png");
    ui->button[1] = b_zoom;
    ui->button[2] = cls;
    ui->button[3] = b_regen;
    ui->button[4] = b_save;
    ui->nb_button = 5;
}

void init_ui2(ui_t *ui)
{
    info_dropdown_t const info_dd_brush_form[] = {
    {"assets/images/form_brush_dropdown.png", BRUSH},
    {"assets/images/rect_form_subbutton.png", SQUARE},
    {"assets/images/cone_form_subbutton.png", CONE},
    {"assets/images/triangle_form_subbutton.png", TRIANGLE},
    {"assets/images/disc_form_subbutton.png", CIRCLE},
    {NULL, -1}
    };
    drop_down_button_t dd_brush_form = {NULL, 0, 0, {20, 290}};

    init_dropdown(&dd_brush_form, info_dd_brush_form);
    ui->dd_brush_form = dd_brush_form;
}

void init_ui(ui_t *ui)
{
    button_t sb = {0, 0, {100, 1080}, {0}, {0, 0}, {0, 0}, 255, SIDEBAR, 0};
    button_t b_move = {0, 0, {64, 64}, {0}, {20, 370}, {0, 0}, 150, MOVE, 0};

    init_obj_ui(&b_move, "assets/images/move_button.png");
    ui->button = malloc(sizeof(button_t) * 5);
    ui->button[0] = b_move;
    init_obj_ui(&sb, "assets/images/sidebar.png");
    ui->sidebar = sb;
    init_ui2(ui);
    init_ui3(ui);
}