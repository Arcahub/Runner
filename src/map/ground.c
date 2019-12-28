/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** ground
*/

#include "my_runner.h"

game_object_t *create_ground(game_object_t *last, sfVector2f pos)
{
    sfFloatRect rect;

    last = create_game_object(last, (char *)GROUND_PATH, pos, SOLID);
    if (last == NULL)
        return (NULL);
    last->move = (sfVector2f) {PLAYER_GROUND_SPEED, 0};
    rect = sfSprite_getLocalBounds(last->sprite);
    last->box = (sfIntRect) {(int)rect.left, (int)rect.top, (int)rect.width, \
    (int)rect.height};
    last->z_index = PLAYER_GROUND;
    last->update = &update_tile;
    return (last);
}

game_object_t *generate_floor(game_object_t *last, float start_x, int width)
{
    int height = TILE_MAX_HEIGHT;

    for (int i = 0; i < width; i++) {
        last = create_ground(last, (sfVector2f) \
        {(float) (start_x + i * TILE_WIDTH), (float) height});
    }
    return (last);
}