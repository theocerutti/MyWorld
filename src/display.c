/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "../include/my_world.h"

void display_dropdown(sfRenderWindow *window, drop_down_button_t dropdown)
{
    sfRenderWindow_drawSprite(window, dropdown.button[0].s, NULL);
    if (dropdown.is_clicked) {
        for (int i = 1; i < dropdown.nb_button; i++) {
            sfRenderWindow_drawSprite(window, dropdown.button[i].s, NULL);
        }
    }
}

void display_ui(sfRenderWindow *window, ui_t *ui)
{
    sfRenderWindow_drawSprite(window, ui->sidebar.s, NULL);
    for (int i = 0; i < ui->nb_button; i++)
        sfRenderWindow_drawSprite(window, ui->button[i].s, NULL);
    display_dropdown(window, ui->dd_brush_form);
}

void display_fps(sfRenderWindow *window, fps_obj_t *fps_obj)
{
    char *str = malloc(sizeof(char) * 15);
    float fps = 0;
    float current_time = 0;

    my_strcpy(str, "FPS: ");
    current_time = sfTime_asSeconds(sfClock_restart(fps_obj->clockk.clockk));
    fps = 1.f / current_time;
    sfText_setString(fps_obj->txt.txt, my_strcat(str, my_itoa(fps)));
    sfRenderWindow_drawText(window, fps_obj->txt.txt, NULL);
    free(str);
}

void display_info(sfRenderWindow *window, data_t *data)
{
    update_txt_info(data);
    sfRenderWindow_drawText(window, data->info.info_control.txt, NULL);
    sfRenderWindow_drawText(window, data->info.size_brush.txt, NULL);
    sfRenderWindow_drawText(window, data->info.hardness_brush.txt, NULL);
    sfRenderWindow_drawText(window, data->info.rotate.txt, NULL);
    sfRenderWindow_drawText(window, data->info.zoom.txt, NULL);
    sfRenderWindow_drawText(window, data->info.name_map.txt, NULL);
    sfRenderWindow_drawText(window, data->info.size_map.txt, NULL);
}

void display_all(sfRenderWindow *window, data_t *data)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, data->bg.s, NULL);
    display_brush_preview(window, &data->map, &data->brush);
    display_ui(window, &data->ui);
    display_fps(window, &data->fps_obj);
    display_info(window, data);
    sfRenderWindow_display(window);
}
