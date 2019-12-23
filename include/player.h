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
void player_input_keyboard(struct game *, sfKeyCode);
void player_input_joystick(struct game *, int);
void player_dash_update(struct game_object *);
void player_attacking_update(struct game_object *, int, struct scene *);
void player_double_jump_update(struct game_object *);
struct game_object *create_right_attack_effect(struct game_object *, sfVector2f);
#endif /* !PLAYER_H_ */
