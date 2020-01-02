/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** my_game
*/

#ifndef MY_GAME_H_
#define MY_GAME_H_

#include <SFML/Graphics.h>

#include "game_object.h"
#include "scene.h"
#include "menu.h"
#include "my_graph.h"

typedef struct game game_t;
typedef struct score score_t;
typedef struct cursor cursor_t;

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

#endif /* !MY_GAME_H_ */
