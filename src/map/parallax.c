/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** parallax
*/

#include "my_runner.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

bool update_parallax(game_object_t *object, scene_t *scene)
{
    move_object(object);
    if (object->pos.x < - object->box.width)
        object->pos.x = object->box.width + object->move.x;
    return (true);
}

game_object_t *init_paralax(game_object_t *last, int z_index, char *path, \
int speed)
{
    game_object_t *object = NULL;
    sfVector2f pos = {0, 0};

    object = create_game_object(last, path, pos, PARALLAX);
    object->box = (sfIntRect) {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    object->move = (sfVector2f) {speed, 0};
    object->z_index = z_index;
    object->update = &update_parallax;
    return (object);
}

game_object_t *init_background3(game_object_t *last)
{
    last = init_paralax(last, PARALLAX2, "templates/parallax/5.png", \
    PARALLAX_SPEED_5);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, PARALLAX2, "templates/parallax/5.png", \
    PARALLAX_SPEED_5);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    last = init_paralax(last, PARALLAX3, "templates/parallax/4.png", \
    PARALLAX_SPEED_4);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, PARALLAX3, "templates/parallax/4.png", \
    PARALLAX_SPEED_4);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    return (last);
}

game_object_t *init_background2(game_object_t *last)
{
    last = init_paralax(last, PARALLAX4, "templates/parallax/2.png", \
    PARALLAX_SPEED_2);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, PARALLAX4, "templates/parallax/2.png", \
    PARALLAX_SPEED_2);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    last = init_paralax(last, PARALLAX5, "templates/parallax/3.png", \
    PARALLAX_SPEED_3);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, PARALLAX5, "templates/parallax/3.png", \
    PARALLAX_SPEED_3);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    return (last);
}

game_object_t *init_background(game_object_t *last)
{
    last = init_paralax(last, FRONT, "templates/parallax/8.png", \
    PARALLAX_SPEED_8);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, FRONT, "templates/parallax/8.png", \
    PARALLAX_SPEED_8);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    last = init_paralax(last, PARALLAX1, "templates/parallax/6.png", \
    PARALLAX_SPEED_6);
    if (last == NULL)
        return (NULL);
    last = init_paralax(last, PARALLAX1, "templates/parallax/6.png", \
    PARALLAX_SPEED_6);
    if (last == NULL)
        return (NULL);
    last->pos.x += last->box.width;
    last = init_background2(last);
    last = init_background3(last);
    return (last);
}