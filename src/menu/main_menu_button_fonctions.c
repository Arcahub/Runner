/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main_menu_button_fonctions
*/

#include "my_runner.h"

void play_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = GAME_SCENE;
}

void options_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = OPTION_SCENE;
}

void exit_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = -1;
    sfRenderWindow_close(scene->window);
}