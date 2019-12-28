/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** menu_options
*/

#include "my_runner.h"
#include <stdlib.h>

static game_object_t *create_option_object_list(void)
{
    game_object_t *object = NULL;

    object = create_indicator(object, (char *)INDICATOR_PATH, \
    (sfVector2f) {INDICATOR_X, INDICATOR_Y});
    object = create_bar(object, (char *) BAR_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y});
    object->box = (sfIntRect) {VOLUME_BAR_X - BAR_BOX_OFFSET / 2, \
    VOLUME_BAR_Y, BAR_WIDTH, BAR_HEIGHT + BAR_BOX_OFFSET};
    object = create_game_object(object, (char *) BAR_BACKGROUND_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y}, DECOR);
    return (object);
}

void draw_options(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_display(window);
}

scene_t *init_options_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->display = OPTION_SCENE;
    scene->handle_event = &handle_event_options;
    scene->z_index_deepth = 0;
    scene->objects_list = create_option_object_list();
    if (scene->objects_list == NULL)
        return (NULL);
    scene->window = game->window->window;
    return (scene);
}