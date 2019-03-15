/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void display_create_save(data_t *data, sfRenderWindow *window, int launch)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 4; i++) {
        anim_sprite(&data->menu.bg[i]);
        sfRenderWindow_drawSprite(window, data->menu.bg[i].s, NULL);
    }
    anim_sprite(&data->menu.world);
    sfRenderWindow_drawSprite(window, data->menu.world.s, NULL);
    if (launch == 2)
        sfRenderWindow_drawSprite(window, data->new_map.enter_name.s, NULL);
    else
        sfRenderWindow_drawSprite(window, data->new_map.enter_size.s, NULL);
    sfRenderWindow_drawText(window, data->new_map.txt_display.txt, NULL);
    sfRenderWindow_display(window);
}

void input_txt_map(data_t *data, sfEvent event, int *launch)
{
    if (event.text.unicode == 8 && data->new_map.lenght >= 1 && \
    *launch == 2) {
        data->new_map.txt[data->new_map.lenght - 1] = '\0';
        data->new_map.lenght -= 1;
        sfText_setString(data->new_map.txt_display.txt, data->new_map.txt);
    } else if (event.text.unicode != 8 && data->new_map.lenght < 19 && \
    *launch == 2 && event.text.unicode != 13) {
        data->new_map.txt[data->new_map.lenght] = event.text.unicode;
        data->new_map.txt[data->new_map.lenght + 1] = '\0';
        data->new_map.lenght += 1;
        sfText_setString(data->new_map.txt_display.txt, data->new_map.txt);
    }
}

void input_txt_size(data_t *data, sfEvent event, int *launch)
{
    if (event.text.unicode == 8 && data->new_map.lenght >= 1 && \
    *launch == 1) {
        data->new_map.size_txt[data->new_map.lenght - 1] = '\0';
        data->new_map.lenght -= 1;
        sfText_setString(data->new_map.txt_display.txt,
        data->new_map.size_txt);

    } else if (event.text.unicode != 8 && data->new_map.lenght < 3 && \
    *launch == 1 && event.text.unicode >= '0' \
    && event.text.unicode <= '9') {
        data->new_map.size_txt[data->new_map.lenght] = event.text.unicode;
        data->new_map.size_txt[data->new_map.lenght + 1] = '\0';
        data->new_map.lenght += 1;
        sfText_setString(data->new_map.txt_display.txt,
        data->new_map.size_txt);
    }
}

void event_create_save(data_t *data, sfEvent event, int *launch)
{
    if (event.type == sfEvtTextEntered) {
        input_txt_map(data, event, launch);
        input_txt_size(data, event, launch);
    }
    if (isKeyPressed(sfKeyReturn) && event.type == sfEvtKeyPressed) {
        if (data->new_map.lenght > 0 && *launch == 2) {
            *launch -= 1;
            data->new_map.lenght = 0;
            sfText_setString(data->new_map.txt_display.txt, "");
        }
        if (data->new_map.lenght > 0 && *launch == 1) {
            *launch -= 1;
        }
    }
}

int already_create(data_t *data, char *comp)
{
    char *str = NULL;
    FILE *fd = fopen("map/name_save", "r");
    size_t size = 1;
    char **map = NULL;

    if (fd == NULL)
        return (EXIT);
    getline(&str, &size, fd);
    fclose(fd);
    map = name_of_map(str, data);
    for (int i = 0; map[i] != NULL; i++) {
        if (my_strncmp(comp, map[i], my_strlen(map[i])) == 0)
            return (0);
    }
    return (1);
}
