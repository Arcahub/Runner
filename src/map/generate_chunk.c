/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** generate_chunk
*/

#include "my_runner.h"
#include <stdlib.h>
#include <time.h>

game_object_t *generate_ground(game_object_t *last, game_object_t *chunk)
{
    int is_ground = 0;
    int width = 0;
    bool was_last_a_pit = false;

    srand(time(NULL));
    for (int i = 0; i < CHUNK_WIDTH;) {
        is_ground = rand() % 4;
        width = rand() % MAX_FLOOR_WIDTH;
        width = (width > 0) ? width : 1;
        if (i == 0 || i + width >= CHUNK_WIDTH || is_ground > 0 \
        || was_last_a_pit == true) {
            last = generate_floor(last, chunk->pos.x + (float)i, width);
            was_last_a_pit = false;
        } else
            was_last_a_pit = true;
        i += (width * TILE_WIDTH);
    }
    return (last);
}


game_object_t *generate_layer(game_object_t *last)
{
    return (last);
}

game_object_t *generate_trap(game_object_t *last)
{
    return (last);
}


game_object_t *generate_mobs(game_object_t *last)
{
    return (last);
}