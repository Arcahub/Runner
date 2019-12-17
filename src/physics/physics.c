/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** physics
*/

#include "my_runner.h"

void collision_objects(game_object_t *actual, game_object_t *object)
{
    sfIntRect intersect;

    if (sfIntRect_intersects(&actual->box, &object->box, NULL)) {
        if (actual->last_pos.y < object->pos.y) {
            actual->move.y = 0;
            actual->pos.y = object->pos.y - actual->box.height;
            actual->box.top = actual->pos.y;
            sfSprite_setPosition(actual->sprite, actual->pos);
        } else if (actual->last_pos.y > object->pos.y) {
            actual->move.y = GRAVITY;
            actual->pos.y = object->pos.y + object->box.height;
            actual->box.top = actual->pos.y;
            sfSprite_setPosition(actual->sprite, actual->pos);
        }
    }
}

void update_physics(game_object_t *actual, scene_t *scene)
{
    sfIntRect tmp = actual->box;

    actual->move.y += GRAVITY;
    actual->box.top += actual->move.y;
    actual->box.left += actual->move.x;
    for (game_object_t *object = scene->objects_list; object; object = object->next) {
        if (object->type == SOLID)
            collision_objects(actual, object);
    }
    actual->box = tmp;
}