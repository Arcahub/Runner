/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include "my_runner.h"
#include <stdlib.h>

game_object_t *create_game_object(game_object_t *last, char *sprite_path, \
sfVector2f pos, object_type type)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(sprite_path, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->pos = pos;
    object->box = (sfIntRect) {0, 0, 0, 0};
    object->type = type;
    object->update = NULL;
    object->anim = NULL;
    object->move = (sfVector2f) {0, 0};
    object->state = 0;
    object->z_index = 0;
    object->next = last;
    return (object);
}


void move_object(game_object_t *object)
{
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void update_objects(game_object_t *object, game_t *game)
{
    while (object) {
        object->update(object, game);
        object = object->next;
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