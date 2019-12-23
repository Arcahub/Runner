/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** effect
*/

#include "my_runner.h"
#include <stdlib.h>

bool update_effect(game_object_t *object, scene_t *scene)
{
    update_game_object_frame(object);
    if (object->anim[object->state].frames_key[object->anim[object->state].frame_id + 1] == NULL)
        return (false);
    return (true);
}

game_object_t *create_effect(game_object_t *last, char *PATH, sfVector2f pos, sfIntRect **KEY_FRAME)
{
    game_object_t *object = create_game_object(last, PATH, pos, EFFECT);

    object->anim = malloc(sizeof(anim_t) * 1);
    object->anim[0].frames_key = KEY_FRAME;
    object->anim[0].loop = false;
    object->anim[0].frame_id = 0;
    object->anim[0].restart_id = 0;
    object->state = 0;
    object->update = &update_effect;
    init_game_object_frame(object);
    return (object);
}