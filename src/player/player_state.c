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
        if (state == ATTACKING_DOWN)
            player->pos.x += PLAYER_ATTACKING_DOWN_OFFSET;
        else if (state == ATTACKING_TOP)
            player->pos.x += PLAYER_ATTACKING_TOP_OFFSET;
        else if (state == ATTACKING_RIGHT)
            player->pos.x += PLAYER_ATTACKING_RIGHT_OFFSET;
        sfSprite_setPosition(player->sprite, player->pos);
        update_game_object_state(player, RUNNING);
    } else if (player->anim[state].frame_id == 2) {
        if (state == ATTACKING_DOWN)
            scene->objects_list = \
            create_down_attack_effect(scene->objects_list, player->pos);
        else if (state == ATTACKING_TOP)
            scene->objects_list = \
            create_top_attack_effect(scene->objects_list, player->pos);
        else if (state == ATTACKING_RIGHT)
            scene->objects_list = \
            create_right_attack_effect(scene->objects_list, player->pos);
    }
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