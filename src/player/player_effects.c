/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** attack_effects
*/

#include "my_runner.h"

game_object_t *create_right_attack_effect(game_object_t *last, sfVector2f pos)
{
    game_object_t *object = create_effect(last, (char *)ATTACK_EFFECT_PATH, \
    pos, (sfIntRect **)RIGHT_ATTACK_EFFECT_FRAME_KEYS);

    object->z_index = PLAYER_DISPLAY;
    return (object);
}

game_object_t *create_top_attack_effect(game_object_t *last, sfVector2f pos)
{
    game_object_t *object = NULL;

    pos.y -= TOP_ATTACK_EFFECT_OFFSET;
    object = create_effect(last, (char *)ATTACK_EFFECT_PATH, pos, \
    (sfIntRect **)TOP_ATTACK_EFFECT_FRAME_KEYS);
    object->z_index = PLAYER_DISPLAY;
    return (object);
}

game_object_t *create_down_attack_effect(game_object_t *last, sfVector2f pos)
{
    game_object_t *object = NULL;

    object = create_effect(last, (char *)ATTACK_EFFECT_PATH, pos, \
    (sfIntRect **)DOWN_ATTACK_EFFECT_FRAME_KEYS);
    object->z_index = PLAYER_DISPLAY;
    return (object);
}