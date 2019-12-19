/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** buttons
*/

#include "my_runner.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

bool update_text_button(game_object_t *button, scene_t *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);

    if (sfIntRect_contains(&button->box, pos.x, pos.y) && button->state != SELECTED)
        update_game_object_state(button, SELECTED);
    else if (!sfIntRect_contains(&button->box, pos.x, pos.y) && button->state != UNSELECTED)
        update_game_object_state(button, UNSELECTED);
    else
        update_game_object_frame(button);
    return (true);
}

anim_t *create_text_button_anim(void)
{
    anim_t *anims = malloc(sizeof(anim_t) * 2);

    if (anims == NULL)
        return (NULL);
    anims[UNSELECTED].frames_key = (sfIntRect **)BUTTON_UNSELECTED_FRAME_KEYS;
    anims[UNSELECTED].loop = true;
    anims[UNSELECTED].frame_id = 0;
    anims[UNSELECTED].restart_id = 11;
    anims[SELECTED].frames_key = (sfIntRect **)BUTTON_SELECTED_FRAME_KEYS;
    anims[SELECTED].loop = true;
    anims[SELECTED].frame_id = 0;
    anims[SELECTED].restart_id = 11;
    return (anims);
}

game_object_t *create_text_button(game_object_t *last, char *path, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, BUTTON);

    object->anim = create_text_button_anim();
    object->update = &update_text_button;
    object->state = UNSELECTED;
    object->anim[object->state].frame_id = object->anim[object->state].restart_id;
    init_game_object_frame(object);
}

