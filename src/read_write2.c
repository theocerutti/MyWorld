/*
** EPITECH PROJECT, 2019
** read_write2.c
** File description:
** read_write2.c
*/

#include "../include/my_world.h"

void get_line_map_save(data_t *data, int l, char *str)
{
    data->map.map_3d[l] = malloc(sizeof(int) * data->map.size.y);
    for (int i = 0; i < data->map.size.y; i++) {
        data->map.map_3d[l][i] = my_getnbr(str);
        while (*str != ',' && *str != '\n')
            str++;
        str++;
    }
}

void initialize_text_map_save(data_t *data, char **map)
{
    int len = 0;

    for (len = 0; map[len] != NULL; len++);
    data->menu.map_name = malloc(sizeof(txt_t) * len);
    data->menu.b_select = malloc(sizeof(button_t) * len);
    for (int i = 0; map[i] != NULL; i++) {
        init_txt_map_save(data, i, map);
    }
}

void init_txt_map_save(data_t *data, int i, char **map)
{
    data->menu.b_select[i].s = NULL;
    data->menu.b_select[i].t = NULL;
    data->menu.b_select[i].offset = (sfVector2f){1700, 60};
    data->menu.b_select[i].rect = (sfIntRect){0, 0, 1700, 60};
    data->menu.b_select[i].pos = (sfVector2f){100, 70 * i + 50};
    data->menu.b_select[i].size = (sfVector2u){50, 50};
    data->menu.b_select[i].alpha = 255;
    data->menu.b_select[i].id = -1;
    data->menu.b_select[i].is_clicked = 0;
    init_obj_ui(&data->menu.b_select[i],
    "assets/images/button_select_map.png");
    data->menu.map_name[i].txt = NULL;
    data->menu.map_name[i].font = NULL;
    data->menu.map_name[i].pos = (sfVector2f){900, 70 * i + 50};
    data->menu.map_name[i].color = sfBlack;
    data->menu.map_name[i].size = 50;
    init_txt(&data->menu.map_name[i],
    "assets/fonts/Roboto-Light.ttf", map[i]);
}

int pool_event_select_map(data_t *data, sfRenderWindow *window, char **map,
int *launch)
{
    sfEvent event = {0};

    for (int j = 0; sfRenderWindow_pollEvent(window, &event); j++) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (EXIT);
        }
        select_map_event(data, window, launch, map);
    }
    return (0);
}