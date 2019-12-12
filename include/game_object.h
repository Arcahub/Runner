/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include <SFML/Graphics.h>

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

struct game_object;

typedef enum {
    PLAYER,
    PARALLAX,
    EFFECT,
} object_type;

void update_game_object_state(struct game_object *, int);
void init_game_object_frame(struct game_object *);
struct game_object *create_game_object(struct game_object *, char *, sfVector2f, object_type);
void update_game_object_frame(struct game_object *);
#endif /* !GAME_OBJECT_H_ */
