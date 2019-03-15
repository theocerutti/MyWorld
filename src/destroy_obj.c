/*
** EPITECH PROJECT, 2019
** destroy_obj
** File description:
** destroy_obj
*/

#include "../include/my_world.h"

void free_2d_map(map_t *map)
{
    for (int i = 0; i < map->size.y; i++) {
        free(map->map_2d[i]);
    }
    free(map->map_2d);
}

void destroy_sfx(sfx_t *sfx)
{
    sfMusic_destroy(sfx->music);
    sfSound_destroy(sfx->sound);
    sfSoundBuffer_destroy(sfx->buffer);
}

void destroy_sprite(sprite_t *s)
{
    sfSprite_destroy(s->s);
    sfTexture_destroy(s->t);
}

void destroy_txt(txt_t *txt)
{
    sfText_destroy(txt->txt);
    sfFont_destroy(txt->font);
}

void destroy_button(button_t *b)
{
    sfSprite_destroy(b->s);
    sfTexture_destroy(b->t);
}