/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

#define isButtonPressed sfMouse_isButtonPressed
#define isKeyPressed sfKeyboard_isKeyPressed

void anim_sprite(sprite_t *s);
void init_sprite(sprite_t *obj, char const *path);
sfVector2f project_iso_point(int x, int y, int z, map_t *map);
sfVector3f **create_2d_map(map_t *map);
void create_3d_map(map_t *map);
void print_3d_map(map_t *map);
void zoom_map(map_t *map, int delta);
void move_map(map_t *map, int x_off, int y_off);
void get_event(sfRenderWindow *window, data_t *d);
sfVector3f transform_3d_point(int x, int y, int z, map_t *map);
int get_higher_altitude(map_t *map);
int get_lower_altitude(map_t *map);
void actualize_map(map_t *map);
void cleanup(data_t *d, sfRenderWindow *window);
sfRenderWindow *create_window(void);
void free_2d_map(map_t *map);
void add_quads(map_t *map, sfColor color[4], sfVector3f point[4]);
void update_alt(sfVector3f point[4], sfVector2i alt);
void update_color(sfColor color[4], sfVector3f point[4]);
void height_brush_size(int i, int j, map_t *map, brush_t *brush);
void display_brush_preview(sfRenderWindow *window, map_t *map, brush_t *brush);
void init_all(data_t *data);
void init_ui(ui_t *ui);
void display_ui(sfRenderWindow *window, ui_t *ui);
int is_clicked(button_t *obj, sfVector2i pos_mouse);
void init_obj_ui(button_t *obj, char const *path);
int is_contain(button_t obj, sfVector2i pos_mouse);
void init_dropdown(drop_down_button_t *dropdown_obj,
info_dropdown_t const info[]);
void display_dropdown(sfRenderWindow *window, drop_down_button_t dropdown);
void init_txt(txt_t *t, char const *path, char const *str);
void init_clock(myclock_t *clockk);
void display_all(sfRenderWindow *window, data_t *data);
void hover_button(button_t *button, sfVector2i pos_mouse);
void hover_all_button(ui_t *ui, sfVector2i pos_mouse);
void select_button(data_t *d, sfVector2i pos_mouse, int button);
sfColor get_color_map(sfVector2i alt, sfVector3f point);
void rotate_side(map_t *map, int rotate_state);
void clear_map(map_t *map);
void rotate_vertical(map_t *map, float rotate_x, float rotate_y);
void select_button_dropdown_form(data_t *d, sfVector2i pos_mouse, int button);
void select_button_dropdown_type(data_t *d, sfVector2i pos_mouse, int button);
int get_form_brush(sfVector2i c, sfVector2i d, brush_t *brush, map_t *map);
void center_map(map_t *map);
void all_brush(sfRenderWindow *window, data_t *d);
void display_help(sfRenderWindow *window, data_t *data);
void display_save(sfRenderWindow *window, data_t *data);
void display_param(sfRenderWindow *window, data_t *data);
void display_color(sfRenderWindow *window, data_t *data);
int menu_loop(data_t *data, sfRenderWindow *window);
void init_menu(data_t *data);
int select_map(data_t *data, sfRenderWindow *window);
void init_all_menu(data_t *data);
void init_sfx(sfx_t *sfx_obj, char const *path);
void destroy_all(data_t *d);
void destroy_sfx(sfx_t *sfx);
void destroy_sprite(sprite_t *s);
void destroy_txt(txt_t *txt);
void destroy_button(button_t *b);
void move_button_evt(data_t *data, sfVector2i pos_mouse,
sfVector2i pos_mouse_last);
void brush_evt(data_t *d, sfRenderWindow *window);
void move_screen_border_evt(data_t *d, sfVector2i pos_mouse);
void brush_type(data_t *d, int type);
int create_save(data_t *data, sfRenderWindow *window);
char *str_cat_malloc(char *str1, char *str2);
void save_map_button_evt(data_t *data);
void clicked_opacity_button_tab(button_t *button, sfVector2i opt,
sfVector2i pos_mouse, int plus);
char **name_of_map(char *str, data_t *data);
void display_info(sfRenderWindow *window, data_t *data);
sfColor hill_color(sfVector3f point);
sfColor mountain_color(sfVector3f point);
sfColor water_color(sfVector3f point);
sfColor sand_color(sfVector3f point);
sfColor dirt_color(sfVector3f point);
void add_quads_good(int i, int j, map_t *map);
void button_click_evt2(data_t *d, sfVector2i pos_mouse,
sfVector2i pos_mouse_last, sfRenderWindow *window);
void button_click_evt1(data_t *d, sfEvent event, sfVector2i pos_mouse);
void button_click_evt3(data_t *d, sfEvent event, sfRenderWindow *window,
sfVector2i pos_mouse);
void update_txt_info(data_t *d);
int pool_event_select_map(data_t *data, sfRenderWindow *window, char **map,
int *launch);
void select_map_event(data_t *data, sfRenderWindow *window, int *launch,
char **map);
void init_txt_map_save(data_t *data, int i, char **map);
void initialize_text_map_save(data_t *data, char **map);
void get_line_map_save(data_t *data, int l, char *str);
int already_create(data_t *data, char *comp);
void event_create_save(data_t *data, sfEvent event, int *launch);
void input_txt_size(data_t *data, sfEvent event, int *launch);
void input_txt_map(data_t *data, sfEvent event, int *launch);
void display_create_save(data_t *data, sfRenderWindow *window, int launch);