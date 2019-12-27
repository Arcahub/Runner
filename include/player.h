/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include <SFML/Graphics.h>

#ifndef PLAYER_H_
#define PLAYER_H_

typedef enum {
    RUNNING,
    JUMPING,
    FALLING,
    DASHING,
    ATTACKING_RIGHT,
    DOUBLE_JUMPING,
    ATTACKING_TOP,
    ATTACKING_DOWN,
    DEAD
} player_state;

struct game_object;
struct scene;
struct game;
struct anim;

struct game_object *init_player(struct game_object *);
void compute_jump(struct game_object *);
bool player_update(struct game_object *, struct scene *);
void player_input_keyboard(struct game *, sfKeyCode);
void player_input_joystick(struct game *, int, sfEvent);
void player_dash_update(struct game_object *);
void player_attacking_update(struct game_object *, int, struct scene *);
void player_double_jump_update(struct game_object *);
struct game_object *create_right_attack_effect(struct game_object *, \
sfVector2f);
struct game_object *create_top_attack_effect(struct game_object *, \
sfVector2f);
struct game_object *create_down_attack_effect(struct game_object *, \
sfVector2f);
struct anim *init_player_anim(void);
void init_player_anim_sound_effect(struct anim *);
void init_player_attack_sound_effect(struct anim *);
bool attack_effect_update(struct game_object *, struct scene *);
#endif /* !PLAYER_H_ */
