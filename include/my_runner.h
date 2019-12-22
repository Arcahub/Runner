/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#define ABS(x)  x = (x < 0) ? - x : x

#include "player.h"
#include "game_object.h"
#include "const.h"
#include "my_graph.h"

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
    DASHING,
    ATTACKING_RIGHT,
    DOUBLE_JUMPING
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
    MAIN_MENU_SCENE,
    OPTION_SCENE,
    NULL_SCENE,
} scene_index;

typedef struct scene {
    void (*handle_event)(struct scene *, struct game *, sfRenderWindow *);
    game_object_t *objects_list;
    sfColor background_color;
    int z_index_deepth;
    int display;
    int joystick_coord_id;
    sfRenderWindow *window;
} scene_t;

typedef struct score {
    unsigned long long int score;
    sfText *text;
} score_t;

typedef struct game {
    window_t *window;
    char *map;
    int (*scene_loop[3]) (game_t *, sfRenderWindow *);
    game_object_t *player;
    score_t *score;
    cursor_t cursor;
}game_t;

game_object_t *init_background(game_object_t *);
void handle_event_game(scene_t *, game_t *, sfRenderWindow *);
void handle_event_main_menu(scene_t *, game_t *, sfRenderWindow *);
void handle_event_options(scene_t *, game_t *, sfRenderWindow *);
int game_loop(game_t *, sfRenderWindow *);
void display_scene(scene_t *, sfRenderWindow *);
bool update_parallax(game_object_t *, scene_t *);
void init_scenes(game_t *, char *);
game_object_t *init_player_ground(game_object_t *, char *);
char *read_map(char *);
void update_physics(game_object_t *, scene_t *);
sfBool check_joystick_button_pressed(int);
void handle_joystick_game(sfEvent, game_t *);
void handle_joystick_menu(sfEvent, game_t *, scene_t *);
scene_t *init_game_scene(game_t *, char *);
game_object_t *create_text_button(game_object_t *, char *, sfVector2f);
void is_click_on_object(scene_t *, sfMouseButtonEvent, game_t *, object_type);
int main_menu_loop(game_t *, sfRenderWindow *);
scene_t *create_main_menu(void);
void play_button_function(game_object_t *, void *);
void exit_button_function(game_object_t *, void *);
void increase_score(game_t *);
void init_score(game_t *);
void destroy_scene(scene_t *);
void destroy_object_list(scene_t *);
void handle_joystick_main_menu(sfEvent, game_t *, scene_t *);
window_t *init_window(void);
void destroy_game(game_t *);
game_t *init_game(char *);
scene_t *init_options_scene(game_t *);
game_object_t *create_indicator(game_object_t *, char *, sfVector2f);
game_object_t *create_bar(game_object_t *, char *, sfVector2f);
int options_loop(game_t *, sfRenderWindow *);
void options_button_function(game_object_t *, void *);
void handle_key_pressed_game(game_t *, sfKeyCode);
void draw_main_menu(scene_t *, game_t *, sfRenderWindow *);
void draw_options(scene_t *, game_t *, sfRenderWindow *);
void draw_game(scene_t *, game_t *, sfRenderWindow *);
void handle_framerate(sfClock *, scene_t *, game_t *);
#endif /* !MY_RUNNER_H_ */
