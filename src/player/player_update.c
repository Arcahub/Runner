/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** player_update
*/

#include "my_runner.h"
#include <stdlib.h>

void check_player_pos_x(game_object_t *player)
{
    float tmp = 0.0;

    if (player->pos.x != PLAYER_START_X)
        player->move.x = PLAYER_START_X - player->pos.x;
    else
        player->move.x = 0;
    tmp = player->move.x;
    if ((ABS(player->move.x)) > PLAYER_MAX_SPEED_X)
        if (tmp < 0)
            player->move.x = - PLAYER_MAX_SPEED_X;
        else
            player->move.x = PLAYER_MAX_SPEED_X;
    else {
        player->move.x = 0;
        player->pos.x = PLAYER_START_X;
    }
}

void update_player_state(game_object_t *player, scene_t *scene)
{
    if (player->state == JUMPING || player->state == FALLING)
        compute_jump(player);
    if (player->state == DASHING)
        player_dash_update(player);
    if(player->state == ATTACKING_RIGHT)
        player_attacking_update(player, ATTACKING_RIGHT, scene);
    if (player->state == DOUBLE_JUMPING)
        player_double_jump_update(player);
}

bool player_update(game_object_t *player, scene_t *scene)
{
    update_game_object_frame(player);
    update_player_state(player, scene);
    move_object(player);
    update_physics(player, scene);
    if (player->move.y > 0 && (player->state == JUMPING || player->state == RUNNING))
        update_game_object_state(player, FALLING);
    if (player->move.y == 0 && player->state == FALLING) {
        update_game_object_state(player, RUNNING);
        if (player->delta_t != NULL) {
            sfClock_destroy(player->delta_t);
            player->delta_t = NULL;
        }
    }
    check_player_pos_x(player);
    return (true);
}