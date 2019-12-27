/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include "my_runner.h"
#include <stdlib.h>
#include <stdbool.h>

void init_game_object(game_object_t *object)
{
    object->update = NULL;
    object->callback = NULL;
    object->anim = NULL;
    object->sound_effect = NULL;
    object->move = (sfVector2f) {0, 0};
    object->state = 0;
    object->z_index = 0;
    object->box = (sfIntRect) {0, 0, 0, 0};
}

game_object_t *create_game_object(game_object_t *last, char *sprite_path, \
sfVector2f pos, object_type type)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(sprite_path, NULL);
    if (object->sprite == NULL || object->texture == NULL)
        return (NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->pos = pos;
    object->type = type;
    object->next = last;
    init_game_object(object);
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}

void move_object(game_object_t *object)
{
    object->last_pos = object->pos;
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void update_objects(scene_t *scene, game_object_t *object, game_t *game)
{
    game_object_t *prev = NULL;
    bool ret = true;

    while (object) {
        if (object->update != NULL)
            ret = object->update(object, scene);
        else {
            object = object->next;
            continue;
        }
        if (ret == false) {
            destroy_game_object(scene, prev, object);
        } else
            prev = object;
        if (prev != NULL)
            object = prev->next;
        else
            object = prev;
    }
}

void draw_objects(game_object_t *object, sfRenderWindow *window, \
int z_index_max)
{
    game_object_t *tmp = object;

    for (int i = z_index_max; i >= 0;) {
        if (object->z_index == i)
            sfRenderWindow_drawSprite(window, object->sprite, NULL);
        object = object->next;
        if (object == NULL) {
            object = tmp;
            i--;
        }
    }
}