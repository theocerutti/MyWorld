/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void create_path(data_t *data)
{
    FILE *file = NULL;
    char *str = NULL;

    if (already_create(data, data->new_map.txt)) {
        file = fopen("map/name_save", "a");
        str = str_cat_malloc(data->new_map.txt, ",");
        fwrite(str, sizeof(char), sizeof(char) * (my_strlen(str)), file);
        fclose(file);
    }
}

void create_file(data_t *data)
{
    FILE *file = NULL;
    char *str = NULL;
    char *cat = str_cat_malloc(data->new_map.size_txt, "\n");

    data->name_map = data->new_map.txt;
    file = fopen(str_cat_malloc("map/", data->new_map.txt), "w");
    fwrite(cat, sizeof(char), sizeof(char) * (my_strlen(cat)), file);
    for (int i = 0; i < data->map.size.x; i++) {
        for (int j = 0; j < data->map.size.x; j++) {
            str = my_itoa(data->map.map_3d[i][j]);
            fwrite(str, sizeof(char), sizeof(char) *
            (my_strlen(str)), file);
            fwrite(",", sizeof(char), sizeof(char), file);
        }
        fwrite("\n", sizeof(char), sizeof(char), file);
    }
    fclose(file);
    create_path(data);
}

void init_create_save(data_t *data)
{
    sprite_t enter_name = {1000, 250, {1000, 255}, 0, 255, {0, 0},
    {460, 585}, 0, 0, {0}, {1, 1}};
    sprite_t enter_size = {1000, 250, {1000, 255}, 0, 255, {0, 0},
    {460, 585}, 0, 0, {0}, {1, 1}};

    data->new_map.lenght = 0;
    for (int i = 0; i < 19; i++) {
        data->new_map.txt[i] = '\0';
        data->new_map.size_txt[i] = '\0';
    }
    init_sprite(&enter_name, "assets/images/text_zone.png");
    init_sprite(&enter_size, "assets/images/text_size.png");
    data->new_map.enter_name = enter_name;
    data->new_map.enter_size = enter_size;
    data->new_map.txt_display.size = 80;
    data->new_map.txt_display.color = (sfColor){0, 0, 0, 255};
    data->new_map.txt_display.pos = (sfVector2f){520, 710};
    init_txt(&data->new_map.txt_display, "assets/fonts/Roboto-Light.ttf", "");
}

int init_loading_map(data_t *data)
{
    if (data->new_map.txt[0] == '\0')
        return (EXIT);
    data->map.size.x = my_getnbr(data->new_map.size_txt);
    data->map.size.y = data->map.size.x;
    create_3d_map(&data->map);
    create_2d_map(&data->map);
    center_map(&data->map);
    create_file(data);
    return (0);
}

int create_save(data_t *data, sfRenderWindow *window)
{
    sfEvent event = {0};
    int launch = 2;

    init_create_save(data);
    while (sfRenderWindow_isOpen(window) && launch > 0) {
        display_create_save(data, window, launch);
        while (sfRenderWindow_pollEvent(window, &event)) {
            event_create_save(data, event, &launch);
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (EXIT);
            }
        }
    }
    return (init_loading_map(data));
}
