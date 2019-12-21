/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include <SFML/Graphics.h>

#ifndef PLAYER_H_
#define PLAYER_H_
struct game_object;
struct scene;
struct game;

struct game_object *init_player(struct game_object *);
void compute_jump(struct game_object *);
bool player_update(struct game_object *, struct scene *);
void player_input(struct game *, sfKeyCode);
void player_dash_update(struct game_object *);
void player_attacking_update(struct game_object *, int);
void player_double_jump_update(struct game_object *);

#endif /* !PLAYER_H_ */
