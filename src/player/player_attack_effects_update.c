/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** player_attack_effects_update
*/

#include "my_runner.h"

static void compute_effect_collide_spike(game_object_t **player, \
game_object_t *effect, game_object_t *object, scene_t *scene) {
    sfIntRect intersect_rect = {0, 0, 0, 0};

    if (sfIntRect_intersects(&effect->box, &object->box, &intersect_rect)) {
        if (*player == NULL)
            *player = find_player(scene);
        if ((*player)->state == ATTACKING_DOWN)
            (*player)->move.y = - 25;
        else if ((*player)->state == ATTACKING_TOP)
            (*player)->move.y = 25;
        else if ((*player)->state == ATTACKING_RIGHT) {
            (*player)->pos.x += - 85;
            sfSprite_setPosition((*player)->sprite, (*player)->pos);
        }
        effect->update = &update_effect;
    }

}

bool attack_effect_update(game_object_t *effect, scene_t *scene)
{
    game_object_t *player = NULL;

    for (game_object_t *object = scene->objects_list; object && \
    effect->update == &attack_effect_update; object = object->next) {
        if (object->type == SPIKES ) {
            compute_effect_collide_spike(&player, effect, object, scene);
        }
    }
    return (update_effect(effect, scene));
}