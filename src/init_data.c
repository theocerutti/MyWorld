/*
** EPITECH PROJECT, 2019
** init_data
** File description:
** init_data
*/

#include "../include/my_world.h"

void init_info2(data_t *data)
{
    txt_t zoom = {NULL, NULL, {1550, 790}, sfWhite, 25};
    txt_t name_map = {NULL, NULL, {1550, 820}, sfWhite, 25};
    txt_t size_map = {NULL, NULL, {1550, 850}, sfWhite, 25};

    init_txt(&zoom, "assets/fonts/Roboto-Light.ttf", "0");
    init_txt(&name_map, "assets/fonts/Roboto-Light.ttf", "Name_Map");
    init_txt(&size_map, "assets/fonts/Roboto-Light.ttf", "0");
    data->info.zoom = zoom;
    data->info.name_map = name_map;
    data->info.size_map = size_map;
}

void init_info(data_t *data)
{
    txt_t info_control = {NULL, NULL, {1550, 550}, sfWhite, 25};
    txt_t size_brush = {NULL, NULL, {1550, 700}, sfWhite, 25};
    txt_t hardness_brush = {NULL, NULL, {1550, 730}, sfWhite, 25};
    txt_t rotate = {NULL, NULL, {1550, 760}, sfWhite, 25};

    init_txt(&info_control, "assets/fonts/Roboto-Light.ttf", \
    "N: Erase Map\nM: New Map\nSpace: Center Map \
    \nShift: Lock vertex\nCtrl: Equalize Map");
    init_txt(&size_brush, "assets/fonts/Roboto-Light.ttf", "0");
    init_txt(&hardness_brush, "assets/fonts/Roboto-Light.ttf", "0");
    init_txt(&rotate, "assets/fonts/Roboto-Light.ttf", "0");
    data->info.info_control = info_control;
    data->info.hardness_brush = hardness_brush;
    data->info.rotate = rotate;
    data->info.size_brush = size_brush;
    data->map.vertex_array = sfVertexArray_create();
    init_info2(data);
}

void init_all(data_t *data)
{
    brush_t brush = {{-1, -1}, 0, {0, 0}, 10, 2, SQUARE};
    ui_t ui = {NULL, 0, {0}, {NULL, 0, 0, {0, 0}}};
    fps_obj_t fps_obj = {{NULL, NULL, {1800, 50}, sfWhite, 20}, {NULL, {0}}};
    sprite_t bg = {1920, 1080, {1920, 1080}, 0, 255, {0, 0}, {0, 0},
    0, 0, {0}, {1.3, 1.3}};

    init_info(data);
    init_sprite(&bg, "assets/images/bg_map.jpg!d");
    init_txt(&fps_obj.txt, "assets/fonts/Roboto-Light.ttf", "FPS: 0");
    init_clock(&fps_obj.clockk);
    data->bg = bg;
    data->ui = ui;
    data->fps_obj = fps_obj;
    data->brush = brush;
    data->map.pos.x = -((data->map.size.x * data->map.zoom) / 2);
    data->map.pos.y = -((data->map.size.y * data->map.zoom) / 2);
    data->selecting_tool = BRUSH;
    create_3d_map(&data->map);
    create_2d_map(&data->map);
    init_ui(&data->ui);
}
