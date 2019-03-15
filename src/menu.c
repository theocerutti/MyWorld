/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void display_menu(data_t *d, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 4; i++) {
        anim_sprite(&d->menu.bg[i]);
        sfRenderWindow_drawSprite(window, d->menu.bg[i].s, NULL);
    }
    sfRenderWindow_drawSprite(window, d->menu.b_load.s, NULL);
    sfRenderWindow_drawSprite(window, d->menu.b_create.s, NULL);
    anim_sprite(&d->menu.world);
    sfRenderWindow_drawSprite(window, d->menu.b_sound.s, NULL);
    sfRenderWindow_drawSprite(window, d->menu.b_quit.s, NULL);
    sfRenderWindow_drawSprite(window, d->menu.world.s, NULL);
    sfRenderWindow_drawText(window, d->menu.title.txt, NULL);
    sfRenderWindow_display(window);
}

void hit_b_sound(data_t *d, sfVector2i pos_mouse, sfEvent event)
{
    if (is_contain(d->menu.b_sound, pos_mouse) &&
    event.type == sfEvtMouseButtonReleased) {
        d->menu.music.volume = (d->menu.music.volume == 0) ? 100 : 0;
        d->menu.b_sound.rect.left = (d->menu.b_sound.rect.left == 0) ? 96 : 0;
        sfSprite_setTextureRect(d->menu.b_sound.s, d->menu.b_sound.rect);
        sfMusic_setVolume(d->menu.music.music, d->menu.music.volume);
    }
}

int hit_box_button(data_t *d, sfRenderWindow *window, int *launch,
sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    static int clicked = 0;

    if (is_clicked(&d->menu.b_load, pos_mouse) && clicked == 0) {
        clicked = 1;
        if (select_map(d, window) == EXIT)
            return (EXIT);
        *launch = 0;
    }
    if (is_clicked(&d->menu.b_quit, pos_mouse))
        return (EXIT);
    if (is_clicked(&d->menu.b_create, pos_mouse)) {
        if (create_save(d, window) == EXIT)
            return (EXIT);
        *launch = 0;
    }
    hit_b_sound(d, pos_mouse, event);
    return (0);
}

int menu_loop(data_t *d, sfRenderWindow *window)
{
    sfEvent event = {0};
    int launch = 1;

    while (sfRenderWindow_isOpen(window) && launch) {
        display_menu(d, window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                return (EXIT);
            if (hit_box_button(d, window, &launch, event) == EXIT)
                return (EXIT);
        }
    }
    return (0);
}
