/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "../include/my_world.h"

void init_star(data_t *data)
{
    sprite_t *bg = malloc(sizeof(sprite_t) * 4);
    sprite_t star1 = {2700, 5341, {540, 763}, 0, 255, {0, 0}, {0, -400},
    0, 0, {0}, {1, 2}};
    sprite_t star2 = {2700, 5341, {540, 763}, 0, 255, {0, 0}, {540, -400},
    0, 0, {0}, {1, 2}};
    sprite_t star3 = {2700, 5341, {540, 763}, 0, 255, {0, 0}, {1080, -400},
    0, 0, {0}, {1, 2}};
    sprite_t star4 = {2700, 5341, {540, 763}, 0, 255, {0, 0}, {1620, -400},
    0, 0, {0}, {1, 2}};

    init_sprite(&star1, "assets/images/star.png");
    init_sprite(&star2, "assets/images/star.png");
    init_sprite(&star3, "assets/images/star.png");
    init_sprite(&star4, "assets/images/star.png");
    bg[0] = star1;
    bg[1] = star2;
    bg[2] = star3;
    bg[3] = star4;
    data->menu.bg = malloc(sizeof(sprite_t) * 4);
    data->menu.bg = bg;
}

void init_button_menu(data_t *data)
{
    button_t b_load = {0, 0, {96, 96}, {0}, {925, 650}, {0, 0}, 255, -1, 0};
    button_t b_create = {0, 0, {96, 96}, {0}, {925, 810}, {0, 0}, 255, -1, 0};
    button_t b_quit = {0, 0, {96, 96}, {0}, {1780, 50}, {0, 0}, 255, -1, 0};
    button_t b_sound = {0, 0, {96, 96}, {0}, {50, 50}, {0, 0}, 255, -1, 0};

    init_obj_ui(&b_load, "assets/images/b_load.png");
    init_obj_ui(&b_create, "assets/images/b_create.png");
    init_obj_ui(&b_quit, "assets/images/b_close.png");
    init_obj_ui(&b_sound, "assets/images/b_sound.png");
    data->menu.b_load = b_load;
    data->menu.b_create = b_create;
    data->menu.b_select = NULL;
    data->menu.b_quit = b_quit;
    data->menu.b_sound = b_sound;
}

void init_menu1(data_t *data)
{
    sprite_t world = {2500, 11280, {500, 282}, 0, 255, {0, 0}, {470, 0},
    0, 0, {0}, {2, 2}};
    txt_t title = {NULL, NULL, {815, 500}, sfWhite, 100};
    sfx_t music_menu = {MUSIC, 100, NULL, NULL, NULL};

    init_sfx(&music_menu, "assets/music/music_menu.ogg");
    init_sprite(&world, "assets/images/planet.png");
    init_txt(&title, "assets/fonts/alienleague.ttf", "My_World");
    data->menu.world = world;
    data->menu.title = title;
    data->menu.music = music_menu;
}

void init_all_menu(data_t *data)
{
    init_star(data);
    init_button_menu(data);
    init_menu1(data);
}
