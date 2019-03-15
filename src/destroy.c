/*
** EPITECH PROJECT, 2019
** destroy_obj
** File description:
** destroy_obj
*/

#include "../include/my_world.h"

void cleanup(data_t *d, sfRenderWindow *window)
{
    destroy_sfx(&d->menu.music);
    for (int i = 0; i < d->map.size.y; i++) {
        free(d->map.map_3d[i]);
    }
    free(d->map.map_3d);
    free_2d_map(&d->map);
    for (int button = 0; button < d->ui.nb_button; button++) {
        sfSprite_destroy(d->ui.button[button].s);
        sfTexture_destroy(d->ui.button[button].t);
    }
    free(d->ui.button);
    sfVertexArray_destroy(d->map.vertex_array);
    sfRenderWindow_destroy(window);
}