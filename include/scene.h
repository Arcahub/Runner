/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.h>

typedef struct game game_t;
typedef struct game_object game_object_t;

typedef struct scene {
    void (*handle_event)(struct scene *, struct game *, sfRenderWindow *);
    game_object_t *objects_list;
    sfColor background_color;
    int z_index_deepth;
    int display;
    int joystick_coord_id;
    sfRenderWindow *window;
} scene_t;

typedef enum {
    GAME_SCENE,
    MAIN_MENU_SCENE,
    OPTION_SCENE,
    NULL_SCENE,
} scene_index;

void display_scene(scene_t *, sfRenderWindow *);
void init_scenes(game_t *, char *);
scene_t *init_game_scene(game_t *, char *);
void handle_framerate(sfClock *, scene_t *, game_t *);
scene_t *create_main_menu(void);
void destroy_scene(scene_t *);
scene_t *init_options_scene(game_t *);
void close_scene(scene_t *, sfRenderWindow *, sfClock *, game_t *);

#endif /* !SCENE_H_ */
