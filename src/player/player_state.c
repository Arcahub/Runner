/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** player_state
*/

#include "my_runner.h"

void player_dash_update(game_object_t *player)
{
    if (player->anim[DASHING].frames_key[player->anim[DASHING].frame_id \
    + 1] == NULL) {
        update_game_object_state(player, RUNNING);
        player->pos.x += PLAYER_DASH_OFFSET;
    }
}

void player_attacking_update(game_object_t *player, int state, scene_t *scene)
{
    if (player->anim[state].frames_key[player->anim[state].frame_id \
    + 1] == NULL) {
        update_game_object_state(player, RUNNING);
        player->pos.x += PLAYER_ATTACKING_RIGHT_OFFSET;
        sfSprite_setPosition(player->sprite, player->pos);
    } else if (player->anim[state].frame_id == 2)
        scene->objects_list = create_right_attack_effect(scene->objects_list, player->pos);
}

void player_double_jump_update(game_object_t *player)
{
    int state = DOUBLE_JUMPING;
    compute_jump(player);
    if (player->anim[state].frames_key[player->anim[state].frame_id \
    + 1] == NULL) {
        update_game_object_state(player, JUMPING);
        player->pos.x += PLAYER_DOUBLE_JUMPING_OFFSET;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    return;
}