/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "../include/my_world.h"

void update_txt_info(data_t *d)
{
    sfText_setString(d->info.size_brush.txt,
    str_cat_malloc("(W+ / X-) Brush Size: ", my_itoa(d->brush.size)));
    sfText_setString(d->info.hardness_brush.txt,
    str_cat_malloc("(C+ / V-) Brush Hardness: ", my_itoa(d->brush.hardness)));
    sfText_setString(d->info.rotate.txt,
    str_cat_malloc("(I / J / K / L) Rotate: ", my_itoa(d->map.rotate_x)));
    sfText_setString(d->info.zoom.txt,
    str_cat_malloc("(Scroll Wheel) Zoom: ", my_itoa(d->map.zoom)));
    sfText_setString(d->info.name_map.txt,
    str_cat_malloc("Map Name: ", d->name_map));
    sfText_setString(d->info.size_map.txt,
    str_cat_malloc("Size Map: ", my_itoa(d->map.size.x)));
}

void anim_sprite(sprite_t *s)
{
    s->rect.left += s->offset[0];
    if (s->rect.left > s->width - s->offset[0]) {
        s->rect.top += s->offset[1];
        s->rect.left = 0;
    }
    if (s->rect.top > s->height - s->offset[1])
        s->rect.top = 0;
    sfSprite_setTextureRect(s->s, s->rect);
}

char *str_cat_malloc(char *str1, char *str2)
{
    int len1 = 0;
    int len2 = 0;
    char *str = NULL;
    int k = 0;

    for (len1 = 0; str1[len1] != '\0'; len1++);
    for (len2 = 0; str2[len2] != '\0'; len2++);
    str = malloc(sizeof(char) * (len1 + len2 + 1));
    for (int i = 0; str1[i] != '\0'; i++) {
        str[k] = str1[i];
        k += 1;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        str[k] = str2[i];
        k += 1;
    }
    str[len1 + len2] = '\0';
    return (str);
}