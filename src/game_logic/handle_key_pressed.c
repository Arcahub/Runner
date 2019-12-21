/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** handle_key_pressed
*/

#include "my_runner.h"

void handle_key_pressed_game(game_t *game, sfKeyCode key)
{
    if (key == sfKeySpace && \
        game->player->move.y == 0 && game->player->state == RUNNING) {
            game->player->delta_t = sfClock_create();
            game->player->move.y = - JUMP_SPEED;
            update_game_object_state(game->player, JUMPING);
        }
    if (key == sfKeyEscape)
        options_loop(game, game->window->window);
}