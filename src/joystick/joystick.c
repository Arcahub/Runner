/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** joystick
*/

#include "my_runner.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdbool.h>

sfBool check_joystick_button_pressed(int button)
{
    return (sfJoystick_isConnected(0) && \
    !sfJoystick_isButtonPressed(button, 0));
}

void handle_joystick_main_menu(sfEvent event, game_t *game, scene_t *scene)
{
    static int id = 0;

    if (event.type == sfEvtMouseMoved)
        game->cursor.displayed = sfTrue;
    if (event.type == sfEvtJoystickMoved) {
        game->cursor.displayed = sfFalse;
        if (event.joystickMove.axis == sfJoystickY && \
        sfJoystick_getAxisPosition(event.joystickMove.joystickId, \
        sfJoystickY) > 98 && id < 2) {
            id += 1;
            sfMouse_setPositionRenderWindow(MAIN_MENU_COORDS[id], NULL);
        } else if (event.joystickMove.axis == sfJoystickY && \
        sfJoystick_getAxisPosition(event.joystickMove.joystickId, \
        sfJoystickY) < - 98 && id > 0) {
            id -= 1;
            sfMouse_setPositionRenderWindow(MAIN_MENU_COORDS[id], NULL);
        }
    }
    if (event.type == sfEvtJoystickButtonPressed && event.joystickButton.button\
     == 0)
        is_click_on_object(scene, event.mouseButton, game, BUTTON);
}

void handle_joystick_game(sfEvent event, game_t *game)
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