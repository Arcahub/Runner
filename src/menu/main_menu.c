/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main_menu
*/

#include "my_runner.h"
#include <stdlib.h>

game_object_t *create_main_menu_buttons(void)
{
    game_object_t *object = NULL;

    object = create_button(object, "templates/menu/play.png", (sfVector2f) {0, 0});
    object->callback = &play_button_function;
    return (object);
}

scene_t *create_main_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_main_menu;
    scene->z_index_deepth = 0;
    scene->objects_list = create_main_menu_buttons();
    return (scene);
}