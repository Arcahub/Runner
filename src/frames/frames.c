/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** frames
*/

#include "my_runner.h"

void init_game_object_frame(game_object_t *game_object)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

void update_game_object_state(game_object_t *game_object, int state)
{
    game_object->state = state;
    anim_t *anim = game_object->anim;

    anim[state].frame_id = 0;
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

void update_game_object_frame(game_object_t *game_object)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    anim[state].frame_id += 1;
    if (anim[state].frames_key[anim[state].frame_id] == NULL) {
        if (anim[state].loop == true)
            anim[state].frame_id = anim[state].restart_id;
        else
            anim[state].frame_id = anim[state].restart_id; // need to change with destroy
    }
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}