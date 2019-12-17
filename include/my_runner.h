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
    NULL_SCENE,
} scene_index;

typedef struct anim {
    sfIntRect **frames_key;
    bool loop;
    int frame_id;
    int restart_id;
} anim_t;

typedef struct scene {
    void (*handle_event)(struct game *, sfRenderWindow *);
    game_object_t *objects_list;
    sfColor background_color;
    int z_index_deepth;
} scene_t;

typedef struct game {
    window_t *window;
    scene_t **scene_list;
    game_object_t *player;
}game_t;

game_object_t *init_background(game_object_t *);
void handle_event_game(game_t *, sfRenderWindow *);
void game_loop(scene_t *, game_t *, sfRenderWindow *);
void display_scene(scene_t *, sfRenderWindow *);
bool update_parallax(game_object_t *, game_t *);
void init_scenes(game_t *, char *);
game_object_t *init_player_ground(game_object_t *, char *);
char *read_map(char *);
void update_physics(game_object_t *, scene_t *);

#endif /* !MY_RUNNER_H_ */
