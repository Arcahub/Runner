/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** handle_key_pressed
*/

#include "my_runner.h"

void handle_key_pressed_game(game_t *game, sfKeyCode key)
{
    player_input_keyboard(game, key);
    if (key == sfKeyEscape)
        options_loop(game, game->window->window);
}