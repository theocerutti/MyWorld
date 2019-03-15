/*
** EPITECH PROJECT, 2019
** event_map
** File description:
** event_map
*/

#include "../include/my_world.h"

void print_select_map(data_t *data, sfRenderWindow *window)
{
    sfColor bg_color = sfColor_fromRGB(25, 25, 112);

    sfRenderWindow_clear(window, bg_color);
    for (int i = 0; i < data->menu.nb_name; i++) {
        sfRenderWindow_drawSprite(window, data->menu.b_select[i].s, NULL);
        sfRenderWindow_drawText(window, data->menu.map_name[i].txt, NULL);
    }
    sfRenderWindow_display(window);
}

void load_map(data_t *data, char *map)
{
    char *str = NULL;
    FILE *fd = fopen(str_cat_malloc("map/", map), "r");
    size_t size = 1;

    data->name_map = map;
    getline(&str, &size, fd);
    data->map.size.x = my_getnbr(str);
    data->map.size.y = my_getnbr(str);
    data->map.map_3d = malloc(sizeof(int *) * data->map.size.y);
    for (int l = 0; l < data->map.size.x; l++) {
        str = NULL;
        getline(&str, &size, fd);
        if (str != NULL) {
            get_line_map_save(data, l, str);
        }
    }
    create_2d_map(&data->map);
}

void select_map_event(data_t *data, sfRenderWindow *window, int *launch,
char **map)
{
    sfColor color_hover = {255, 255, 255, 255};
    sfColor color_normal = {255, 255, 255, 150};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < data->menu.nb_name; i++) {
        if (is_contain(data->menu.b_select[i], pos_mouse)) {
            sfSprite_setColor(data->menu.b_select[i].s, color_hover);
        } else {
            sfSprite_setColor(data->menu.b_select[i].s, color_normal);
        }
        if (is_clicked(&data->menu.b_select[i], pos_mouse)) {
            *launch = 0;
            load_map(data, map[i]);
            my_strcpy(data->new_map.txt, map[i]);
        }
    }
}

char **name_of_map(char *str, data_t *data)
{
    char **map = NULL;
    int count = 0;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',')
            count++;
    }
    map = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        for (len = 0; str[len] != ',' && str[len] != '\0'; len++);
        map[i] = malloc(sizeof(char) * len + 1);
        for (int j = 0; str[j] != ',' && str[j] != '\0'; j++)
            map[i][j] = str[j];
        map[i][len] = '\0';
        str += len + 1;
    }
    data->menu.nb_name = count;
    map[count] = NULL;
    return (map);
}

int select_map(data_t *data, sfRenderWindow *window)
{
    char *str = NULL;
    FILE *fd = fopen("map/name_save", "r");
    size_t size = 1;
    char **map = NULL;

    getline(&str, &size, fd);
    fclose(fd);
    map = name_of_map(str, data);
    initialize_text_map_save(data, map);
    for (int launch = 1; sfRenderWindow_isOpen(window) && launch == 1;) {
        if (pool_event_select_map(data, window, map, &launch) == EXIT)
            return (EXIT);
        print_select_map(data, window);
    }
    return (0);
}
