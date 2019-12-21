/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include "my_runner.h"
#include <stdlib.h>

void check_player_pos_x(game_object_t *player)
{
    if (player->pos.x != PLAYER_START_X)
        player->move.x = player->pos.x - PLAYER_START_X;
    else
        player->move.x = 0;
    if (ABS(player->move.x) > PLAYER_MAX_SPEED_X)
        player->move.x = PLAYER_MAX_SPEED_X;
}

bool player_update(game_object_t *player, scene_t *scene)
{
    update_game_object_frame(player);
    if (player->state != RUNNING && player->delta_t != NULL)
        compute_jump(player);
    move_object(player);
    update_physics(player, scene);
    if (player->move.y > 0 && player->state != FALLING)
        update_game_object_state(player, FALLING);
    if (player->move.y == 0 && player->state != RUNNING)
        update_game_object_state(player, RUNNING);
    check_player_pos_x(player);
    return (true);
}

anim_t *init_player_anim(void)
{
    anim_t *anims = malloc(sizeof(anim_t) * 3);

    if (anims == NULL)
        return (NULL);
    anims[RUNNING].frames_key = (sfIntRect **)PLAYER_RUNNING_FRAME_KEYS;
    anims[RUNNING].loop = true;
    anims[RUNNING].frame_id = 0;
    anims[RUNNING].restart_id = 0;
    anims[JUMPING].frames_key = (sfIntRect **)PLAYER_JUMPING_FRAME_KEYS;
    anims[JUMPING].loop = true;
    anims[JUMPING].frame_id = 0;
    anims[JUMPING].restart_id = 0;
    anims[FALLING].frames_key = (sfIntRect **)PLAYER_FALLING_FRAME_KEYS;
    anims[FALLING].loop = true;
    anims[FALLING].frame_id = 0;
    anims[FALLING].restart_id = 4;
    return (anims);
}

game_object_t *init_player(game_object_t *last)
{
    game_object_t *player = NULL;
    sfVector2f pos = {PLAYER_START_X, PLAYER_START_Y};

    player = create_game_object(last, (char *)PLAYER_SPRITE_PATH, pos, PLAYER);
    player->update = &player_update;
    player->move = (sfVector2f) {PLAYER_SPEED_X, PLAYER_SPEED_Y};
    player->state = RUNNING;
    player->z_index = PLAYER_GROUND;
    player->anim = init_player_anim();
    player->delta_t = NULL;
    if (player->anim == NULL)
        return (NULL);
    init_game_object_frame(player);
    return (player);
}