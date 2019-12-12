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

struct game_object *init_player(struct game_object *);
void compute_jump(struct game_object *, sfClock **);

#endif /* !PLAYER_H_ */
