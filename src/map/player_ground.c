/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** player_ground
*/

#include "my_runner.h"
#include <SFML/Graphics.h>

bool update_ground(game_object_t *object, scene_t *scene)
{
    move_object(object);
    if (object->pos.x < - (float)object->box.width)
        return (false);
    return (true);
}

game_object_t *create_ground(game_object_t *last, sfVector2f pos)
{
    sfFloatRect rect;

    last = create_game_object(last, (char *)GROUND_PATH, pos, SOLID);
    last->move = (sfVector2f) {-15, 0};
    rect = sfSprite_getLocalBounds(last->sprite);
    last->box = (sfIntRect) {(int)rect.left, (int)rect.top, (int)rect.width, \
    (int)rect.height};
    last->z_index = PLAYER_GROUND;
    last->update = &update_ground;
    return (last);
}

game_object_t *compute_tile(game_object_t *last, char id, sfVector2f pos)
{
    switch (id) {
        case '1':
            return (create_ground(last, pos));
            break;
    }
    return (last);
}

game_object_t *init_player_ground(game_object_t *last, char *map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; map[i] != '\0'; i++, x++) {
        if (map[i] == '\n') {
            y++;
            x = -1;
        } else if (map[i] != ' ')
            last = compute_tile(last, map[i], (sfVector2f){x  * 100, y * 50});
    }
    return (last);
}