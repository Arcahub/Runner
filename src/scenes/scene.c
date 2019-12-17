/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** scene
*/

#include "my_runner.h"
#include <stdlib.h>

scene_t *init_game_scene(game_t * game, char *map)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->background_color = GAME_BACKGROUND_COLOR;
    scene->handle_event = &handle_event_game;
    scene->objects_list = init_player(NULL);
    game->player = scene->objects_list;
    scene->objects_list = init_background(scene->objects_list);
    scene->objects_list = init_player_ground(scene->objects_list, map);
    scene->z_index_deepth = PARALLAX5;
    return (scene);
}

void display_scene(scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, scene->background_color);
    draw_objects(scene->objects_list, window, scene->z_index_deepth);
}

void init_scenes(game_t *game, char *map)
{
    scene_t **scene_list = malloc(sizeof(scene_t *) * 2);

    scene_list[NULL_SCENE] = NULL;
    scene_list[GAME_SCENE] = init_game_scene(game, map);
    game->scene_list = scene_list;
}