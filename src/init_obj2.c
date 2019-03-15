/*
** EPITECH PROJECT, 2019
** init_obj
** File description:
** init_obj
*/

#include "../include/my_world.h"

void init_clock(myclock_t *clockk)
{
    clockk->clockk = sfClock_create();
    clockk->time = sfClock_getElapsedTime(clockk->clockk);
}

void init_sfx(sfx_t *sfx_obj, char const *path)
{
    if (sfx_obj->type == MUSIC) {
        sfx_obj->music = sfMusic_createFromFile(path);
        sfMusic_setVolume(sfx_obj->music, sfx_obj->volume);
        sfMusic_setLoop(sfx_obj->music, sfTrue);
    } else if (sfx_obj->type == SOUND) {
        sfx_obj->buffer = sfSoundBuffer_createFromFile(path);
        sfx_obj->sound = sfSound_create();
        sfSound_setBuffer(sfx_obj->sound, sfx_obj->buffer);
        sfSound_setVolume(sfx_obj->sound, sfx_obj->volume);
    }
}