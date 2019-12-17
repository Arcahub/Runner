/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** joystick
*/

#include "my_runner.h"
#include <SFML/Graphics.h>
#include <stdbool.h>

sfBool check_joystick_button_pressed(int button)
{
    return (sfJoystick_isConnected(0) && \
    !sfJoystick_isButtonPressed(button, 0));
}

void handle_joystick(sfEvent event, game_t *game)
{
    if (event.type == sfEvtJoystickButtonPressed && event.joystickButton.button\
     == 0 && game->player->move.y == 0 && game->player->state == RUNNING) {
        game->player->delta_t = sfClock_create();
        game->player->move.y = - JUMP_SPEED;
        update_game_object_state(game->player, JUMPING);
    } else if (event.type == sfEvtJoystickButtonReleased &&  \
    event.joystickButton.button == 0 && game->player->state == JUMPING) {
        if (game->player->move.y < JUMP_SPEED_MIN)
        game->player->move.y = - JUMP_SPEED_MIN;
        update_game_object_state(game->player, FALLING);
    }
}