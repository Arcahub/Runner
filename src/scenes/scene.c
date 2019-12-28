/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** scene
*/

#include "my_runner.h"
#include <stdlib.h>

void destroy_scene(scene_t *scene)
{
    if (scene != NULL) {
        destroy_object_list(scene);
        free(scene);
    }
}

void display_scene(scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, scene->background_color);
    draw_objects(scene->objects_list, window, scene->z_index_deepth);
}