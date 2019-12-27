/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** spikes
*/

#include "my_runner.h"

game_object_t *create_spike(game_object_t *last, sfVector2f pos)
{
    sfFloatRect rect;

    last = create_game_object(last, (char *)SPIKES_PATH, pos, SPIKES);
    if (last == NULL)
        return (NULL);
    last->move = (sfVector2f) {-15, 0};
    rect = sfSprite_getLocalBounds(last->sprite);
    last->box = (sfIntRect) {(int)rect.left, (int)rect.top, (int)rect.width, \
    (int)rect.height};
    last->z_index = PLAYER_GROUND;
    last->update = &update_tile;
    return (last);
}