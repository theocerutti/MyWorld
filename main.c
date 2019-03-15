/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "include/my_world.h"

void loop_world(sfRenderWindow *window, data_t *data)
{
    actualize_map(&data->map);
    while (sfRenderWindow_isOpen(window)) {
        get_event(window, data);
        display_all(window, data);
    }
}

int main(void)
{
    sfRenderWindow *window = create_window();
    data_t data;
    map_t map = {{{0}, 0, 1, 110}, NULL, NULL, 2, {0, 0}, 35, 45, {100, 100},
    {300, -100}, NULL};
    int ret_menu = 0;

    data.map = map;
    srand(time(NULL));
    init_all_menu(&data);
    init_all(&data);
    sfMusic_play(data.menu.music.music);
    ret_menu = menu_loop(&data, window);
    sfMusic_stop(data.menu.music.music);
    if (ret_menu != EXIT) {
        loop_world(window, &data);
    }
    cleanup(&data, window);
    return (0);
}
