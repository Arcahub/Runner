/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** in_game_menu
*/

#include "my_runner.h"
#include <stdlib.h>

game_object_t *create_in_game_menu_objects(void)
{
    game_object_t *object = NULL;

    object = create_text_button(object, (char *)PLAY_BUTTON_PATH, \
    (sfVector2f) {PLAY_BUTTON_X, PLAY_BUTTON_Y});
    object->callback = &play_button_function;
    object = create_text_button(object, (char *)OPTION_BUTTON_PATH, \
    (sfVector2f) {OPTION_BUTTON_X, OPTION_BUTTON_Y});
    object->callback = &options_button_function;
    object = create_text_button(object, (char *)INFOS_BUTTON_PATH, \
    (sfVector2f) {INFOS_BUTTON_X, INFOS_BUTTON_Y});
    object->callback = &options_button_function;
    object = create_text_button(object, (char *)EXIT_BUTTON_PATH, \
    (sfVector2f) {EXIT_BUTTON_X, EXIT_BUTTON_Y});
    object->callback = &exit_button_function;
    object = create_game_object(object, \
    "templates/menu/in_game_menu_background.png", (sfVector2f) {0, 0}, DECOR);
    return (object);
}

scene_t *create_in_game_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_in_game_menu;
    scene->z_index_deepth = 0;
    scene->objects_list = create_in_game_menu_objects();
    return (scene);
}

int do_in_game_menu(game_t *game, scene_t *scene)
{
    int display = IN_GAME_MENU_SCENE;

    sfSound_pause(game->player->sound_effect);
    while (display != MAIN_MENU_SCENE && display != GAME_SCENE && \
    display != -1) {
        if (display != IN_GAME_MENU_SCENE) {
            display = game->scene_loop[display](game, game->window->window);
            display = (display == MAIN_MENU_SCENE) ? IN_GAME_MENU_SCENE : display;
        } else
            display = in_game_menu_loop(game, game->window->window, scene);
    }
    sfSound_play(game->player->sound_effect);
    return (display);
}