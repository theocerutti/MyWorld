/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define ui_obj_t button_t
#define EXIT -1

typedef struct data_s data_t;

enum rotate_state {
    LEFT,
    RIGHT
};

enum name_button {
    BRUSH,
    FORM,
    MOVE,
    ZOOM,
    CLEAR_MAP,
    SAVE,
    REGEN,
    SIDEBAR,
    DROP_DOWN_OBJ
};

enum form_brush {
    SQUARE = 1,
    CIRCLE = 2,
    SPHERE = 3,
    TRIANGLE = 4,
    CONE = 5
};

enum type_sfx {
    MUSIC,
    SOUND
};

typedef struct sfx_t {
    int type;
    int volume;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfMusic *music;
} sfx_t;

typedef struct info_dropdown_s {
    char const *path;
    int id;
} info_dropdown_t;

typedef struct txt_s {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
} txt_t;

typedef struct myclock_s {
    sfClock *clockk;
    sfTime time;
} myclock_t;

typedef struct button_s {
    sfTexture *t;
    sfSprite *s;
    sfVector2f offset;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2u size;
    int alpha;
    int id;
    int is_clicked;
} button_t;

typedef struct sprite_s {
    int width;
    int height;
    int offset[2];
    int state;
    sfUint8 alpha;
    sfVector2f v;
    sfVector2f pos;
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
    sfVector2f scale;
} sprite_t;

typedef struct drop_down_button_s {
    button_t *button;
    int nb_button;
    int is_clicked;
    sfVector2f pos;
} drop_down_button_t;

typedef struct ui_s {
    button_t *button;
    int nb_button;
    ui_obj_t sidebar;
    drop_down_button_t dd_brush_form;
} ui_t;

typedef struct brush_s {
    sfVector2i middle_point;
    int hight;
    sfVector2i mouse;
    float size;
    int hardness;
    int form;
} brush_t;

typedef struct perlin_noise_info_s {
    unsigned int tab_noise[256];
    int resolution;
    int mountain_set;
    int alt_set;
} perlin_noise_info_t;

typedef struct map_s {
    perlin_noise_info_t info_perlin;
    int **map_3d;
    sfVector3f **map_2d;
    int zoom;
    sfVector2f pos;
    float rotate_x;
    float rotate_y;
    sfVector2i size;
    sfVector2i alt;
    sfVertexArray *vertex_array;
} map_t;

typedef struct fps_obj_s {
    txt_t txt;
    myclock_t clockk;
} fps_obj_t;

typedef struct menu_s {
    button_t b_load;
    button_t b_create;
    button_t *b_select;
    button_t b_quit;
    button_t b_sound;
    txt_t *map_name;
    int nb_name;
    sprite_t world;
    sprite_t *bg;
    txt_t title;
    sfx_t music;
} menu_t;

typedef struct write_text_s {
    char txt[19];
    char size_txt[19];
    txt_t txt_display;
    int lenght;
    int size;
    sprite_t enter_name;
    sprite_t enter_size;
} write_text_t;

typedef struct info_s {
    txt_t size_brush;
    txt_t hardness_brush;
    txt_t rotate;
    txt_t zoom;
    txt_t name_map;
    txt_t size_map;
    txt_t info_control;
} info_t;

typedef struct data_s {
    info_t info;
    ui_t ui;
    map_t map;
    brush_t brush;
    fps_obj_t fps_obj;
    int selecting_tool;
    menu_t menu;
    sprite_t bg;
    write_text_t new_map;
    char *name_map;
} data_t;
