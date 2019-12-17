/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#include "const.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include "player.h"
#include "game_object.h"

typedef struct game_object game_object_t;

typedef enum {
    JUMP_KEY = sfKeySpace,
    RELEASED = sfEvtKeyReleased,
    PRESSED = sfEvtKeyPressed,
} event;

typedef enum {
    RUNNING,
    JUMPING,
    FALLING,
} player_state;

typedef enum {
    SELECTED,
    UNSELECTED
} button_state;

typedef enum {
    FRONT,
    PLAYER_GROUND,
    PARALLAX1,
    PARALLAX2,
    PARALLAX3,
    PARALLAX4,
    PARALLAX5,
} z_index_game;

typedef enum {
    GAME_SCENE,
    MENU_SCENE,
    NULL_SCENE,
} scene_index;

typedef struct scene {
    void (*handle_event)(struct scene *, struct game *, sfRenderWindow *);
    game_object_t *objects_list;
    sfColor background_color;
    int z_index_deepth;
    int display;
    sfRenderWindow *window;
} scene_t;

typedef struct game {
    window_t *window;
    char *map;
    int (*scene_loop[2]) (game_t *, sfRenderWindow *);
    game_object_t *player;
}game_t;

game_object_t *init_background(game_object_t *);
void handle_event_game(scene_t *, game_t *, sfRenderWindow *);
void handle_event_main_menu(scene_t *, game_t *, sfRenderWindow *);
int game_loop(game_t *, sfRenderWindow *);
void display_scene(scene_t *, sfRenderWindow *);
bool update_parallax(game_object_t *, scene_t *);
void init_scenes(game_t *, char *);
game_object_t *init_player_ground(game_object_t *, char *);
char *read_map(char *);
void update_physics(game_object_t *, scene_t *);
sfBool check_joystick_button_pressed(int);
void handle_joystick(sfEvent, game_t *);
scene_t *init_game_scene(game_t *, char *);
game_object_t *create_button(game_object_t *, char *, sfVector2f);
void is_click_on_button(scene_t *, sfMouseButtonEvent, game_t *);
int main_menu_loop(game_t *, sfRenderWindow *);
scene_t *create_main_menu(void);
void play_button_function(game_object_t *, void *);

#endif /* !MY_RUNNER_H_ */
