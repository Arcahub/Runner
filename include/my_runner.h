/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#define ABS(x)  x = (x < 0) ? - x : x

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "player.h"
#include "game_object.h"
#include "game_logic.h"
#include "map.h"
#include "menu.h"
#include "scene.h"
#include "const.h"
#include "my_graph.h"
#include "my_mysql.h"

typedef struct game_object game_object_t;

typedef enum {
    JUMP_KEY = sfKeySpace,
    RELEASED = sfEvtKeyReleased,
    PRESSED = sfEvtKeyPressed,
} event;

typedef struct score {
    unsigned long long int score;
    sfText *text;
    char *score_text;
} score_t;

typedef struct game {
    window_t *window;
    char *map;
    int (*scene_loop[5]) (game_t *, sfRenderWindow *);
    game_object_t *player;
    score_t *score;
    score_t *highscore;
    void *mysql;
    cursor_t cursor;
}game_t;

game_t *init_game(char *);
int game_loop(game_t *, sfRenderWindow *);
void destroy_game(game_t *);
void draw_game(scene_t *, game_t *, sfRenderWindow *);

void update_physics(game_object_t *, scene_t *);
void increase_score(game_t *);
void init_score(game_t *);
void init_high_score(game_t *);
#endif /* !MY_RUNNER_H_ */
