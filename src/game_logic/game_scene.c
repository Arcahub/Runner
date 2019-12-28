/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_scene
*/

#include "my_runner.h"
#include <stdlib.h>

void draw_game(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_drawText(window, game->score->text, NULL);
    sfRenderWindow_display(window);
}

scene_t *init_game_scene(game_t * game, char *map)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = GAME_BACKGROUND_COLOR;
    scene->handle_event = &handle_event_game;
    scene->objects_list = init_player(NULL);
    if (scene->objects_list == NULL)
        return (NULL);
    game->player = scene->objects_list;
    game->score->score = 0;
    scene->objects_list = init_background(scene->objects_list);
    if (scene->objects_list == NULL)
        return (NULL);
    scene->objects_list = init_player_ground(scene->objects_list, map);
    if (scene->objects_list == NULL)
        return (NULL);
    scene->z_index_deepth = PARALLAX5;
    return (scene);
}
