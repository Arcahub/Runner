/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include "my_runner.h"
#include <stdlib.h>

void init_player_anim_sound_effect(anim_t *anims)
{
    anims[RUNNING].sound_loop = true;
    anims[RUNNING].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_RUNNING_SOUND_PATH);
    anims[JUMPING].sound_loop = false;
    anims[JUMPING].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_JUMPING_SOUND_PATH);
    anims[FALLING].sound_loop = true;
    anims[FALLING].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_FALLING_SOUND_PATH);
    anims[DASHING].sound_loop = false;
    anims[DASHING].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_DASHING_SOUND_PATH);
    anims[ATTACKING_RIGHT].sound_loop = false;
    anims[ATTACKING_RIGHT].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
    anims[DOUBLE_JUMPING].sound_loop = false;
    anims[DOUBLE_JUMPING].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_DOUBLE_JUMPING_SOUND_PATH);
    anims[ATTACKING_TOP].sound_loop = false;
    anims[ATTACKING_TOP].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
    anims[ATTACKING_DOWN].sound_loop = false;
    anims[ATTACKING_DOWN].sound_buffer = sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
}

void init_player_other_anim(anim_t *anims)
{
    anims[DASHING].frames_key = (sfIntRect **)PLAYER_DASHING_FRAME_KEYS;
    anims[DASHING].loop = false;
    anims[DASHING].frame_id = 0;
    anims[DASHING].restart_id = 0;
    anims[ATTACKING_RIGHT].frames_key = (sfIntRect **)PLAYER_ATTACKING_RIGHT_FRAME_KEYS;
    anims[ATTACKING_RIGHT].loop = false;
    anims[ATTACKING_RIGHT].frame_id = 0;
    anims[ATTACKING_RIGHT].restart_id = 0;
    anims[DOUBLE_JUMPING].frames_key = (sfIntRect **)PLAYER_DOUBLE_JUMPING_FRAME_KEYS;
    anims[DOUBLE_JUMPING].loop = false;
    anims[DOUBLE_JUMPING].frame_id = 0;
    anims[DOUBLE_JUMPING].restart_id = 0;
    anims[ATTACKING_TOP].frames_key = (sfIntRect **)PLAYER_ATTACKING_TOP_FRAME_KEYS;
    anims[ATTACKING_TOP].loop = false;
    anims[ATTACKING_TOP].frame_id = 0;
    anims[ATTACKING_TOP].restart_id = 0;
    anims[ATTACKING_DOWN].frames_key = (sfIntRect **)PLAYER_ATTACKING_DOWN_FRAME_KEYS;
    anims[ATTACKING_DOWN].loop = false;
    anims[ATTACKING_DOWN].frame_id = 0;
    anims[ATTACKING_DOWN].restart_id = 0;
}

anim_t *init_player_anim(void)
{
    anim_t *anims = malloc(sizeof(anim_t) * 9);

    if (anims == NULL)
        return (NULL);
    anims[8].sound_buffer = NULL;
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
    init_player_other_anim(anims);
    init_player_anim_sound_effect(anims);
    return (anims);
}

game_object_t *init_player(game_object_t *last)
{
    game_object_t *player = NULL;
    sfVector2f pos = {PLAYER_START_X, PLAYER_START_Y};

    player = create_game_object(last, (char *)PLAYER_SPRITE_PATH, pos, PLAYER);
    player->update = &player_update;
    player->move = (sfVector2f){PLAYER_SPEED_X, PLAYER_SPEED_Y};
    player->state = RUNNING;
    player->z_index = PLAYER_DISPLAY;
    player->anim = init_player_anim();
    player->delta_t = NULL;
    player->sound_effect = sfSound_create();
    if (player->anim == NULL)
        return (NULL);
    init_game_object_frame(player);
    return (player);
}