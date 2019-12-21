/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** free_objects
*/

#include "my_runner.h"
#include <stdlib.h>

void destroy_game_object(scene_t *scene, game_object_t *prev, game_object_t *object)
{
    if (prev == NULL)
        scene->objects_list = object->next;
    else
        prev->next = object->next;
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    if (object->sound_effect != NULL) {
        sfSound_stop(object->sound_effect);
        sfSound_destroy(object->sound_effect);
    }
    if (object->anim != NULL && object->sound_effect != NULL)
        for (int i = 0; object->anim[i].sound_buffer != NULL; i++)
            sfSoundBuffer_destroy(object->anim[i].sound_buffer);
    free(object->anim);
    free(object);
}

void destroy_object_list(scene_t *scene)
{
    while (scene->objects_list)
        destroy_game_object(scene, NULL, scene->objects_list);
}