/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;
typedef struct scene scene_t;

typedef enum {
    FRONT,
    PLAYER_GROUND,
    PLAYER_DISPLAY,
    PARALLAX1,
    PARALLAX2,
    PARALLAX3,
    PARALLAX4,
    PARALLAX5,
} z_index_game;

game_object_t *init_background(game_object_t *);
game_object_t *init_player_ground(game_object_t *, char *);
bool update_parallax(game_object_t *, scene_t *);
bool update_tile(game_object_t *, scene_t *);
char *read_map(char *);

game_object_t *create_spike(game_object_t *, sfVector2f);

#endif /* !MAP_H_ */
