/*
** EPITECH PROJECT, 2019
** init_obj
** File description:
** init_obj
*/

#include "../include/my_world.h"

void init_txt(txt_t *t, char const *path, char const *str)
{
    t->txt = sfText_create();
    t->font = sfFont_createFromFile(path);
    sfText_setString(t->txt, str);
    sfText_setFont(t->txt, t->font);
    sfText_setCharacterSize(t->txt, t->size);
    sfText_setPosition(t->txt, t->pos);
    sfText_setColor(t->txt, t->color);
}

void init_sprite(sprite_t *obj, char const *path)
{
    sfColor color = {255, 255, 255, obj->alpha};
    sfVector2u width_height = {0, 0};

    obj->t = sfTexture_createFromFile(path, NULL);
    obj->s = sfSprite_create();
    width_height = sfTexture_getSize(obj->t);
    obj->width = width_height.x;
    obj->height = width_height.y;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = obj->offset[0];
    obj->rect.height = obj->offset[1];
    sfSprite_setPosition(obj->s, obj->pos);
    sfSprite_setTexture(obj->s, obj->t, sfTrue);
    sfSprite_setTextureRect(obj->s, obj->rect);
    sfSprite_setColor(obj->s, color);
    sfSprite_setScale(obj->s, obj->scale);
}

void init_obj_ui(button_t *obj, char const *path)
{
    sfVector2u width_height = {0, 0};
    sfColor color_obj = {255, 255, 255, obj->alpha};

    obj->t = sfTexture_createFromFile(path, NULL);
    obj->s = sfSprite_create();
    width_height = sfTexture_getSize(obj->t);
    obj->size.x = width_height.x;
    obj->size.y = width_height.y;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = obj->offset.x;
    obj->rect.height = obj->offset.y;
    sfSprite_setPosition(obj->s, obj->pos);
    sfSprite_setTexture(obj->s, obj->t, sfTrue);
    sfSprite_setTextureRect(obj->s, obj->rect);
    sfSprite_setColor(obj->s, color_obj);
}

void init_dropdown(drop_down_button_t *dropdown_obj,
info_dropdown_t const info[])
{
    button_t b = {NULL, NULL, {64, 64}, {0}, {dropdown_obj->pos.x,
    dropdown_obj->pos.y}, {0, 0}, 150, DROP_DOWN_OBJ, 0};
    int nb_button = 0;

    for (nb_button = 0; info[nb_button].path != NULL; nb_button++);
    dropdown_obj->nb_button = nb_button;
    dropdown_obj->button = malloc(sizeof(button_t) * nb_button);
    for (int i = 0; info[i].path != NULL; i++) {
        init_obj_ui(&b, info[i].path);
        b.id = info[i].id;
        dropdown_obj->button[i] = b;
        b.pos.x += 70;
        if (i == 0)
            b.pos.x += 20;
        if (i % 5 == 0 && i != 0) {
            b.pos.x = dropdown_obj->pos.x + 90;
            b.pos.y += 70;
        }
    }
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "MyWorld", sfResize | sfClose, NULL);
    if (!window)
        return (0);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, 1);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}
