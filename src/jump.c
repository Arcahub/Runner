/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** jump
*/

#include "my_runner.h"

void compute_jump(game_object_t *player, sfClock **jump)
{
    sfTime time;
    float seconds = sfClock_getElapsedTime(*jump).microseconds / 1000000.0;

    player->move.y += GRAVITY * seconds;
    if (player->move.y > FALLING_MAX_SPEED)
        player->move.y = FALLING_MAX_SPEED;
    if (player->state == JUMPING && (seconds >= 0.75 || player->move.y > 0)) {
        update_game_object_state(player, FALLING);
    }
    else if (player->state == JUMPING && !sfKeyboard_isKeyPressed(JUMP_KEY))
        if (player->move.y < JUMP_SPEED_MIN)
            player->move.y = - JUMP_SPEED_MIN;
    if (player->move.y + player->pos.y > PLAYER_START_Y) {
        player->move.y = 0;
        player->pos.y = PLAYER_START_Y;
        sfSprite_setPosition(player->sprite, player->pos);
        player->state = RUNNING;
        sfClock_destroy(*jump);
    }
}