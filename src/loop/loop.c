/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** loop
*/

#include "my_runner.h"

int main_menu_loop(game_t *game, sfRenderWindow *window)
{
    int frames = 0;
    scene_t *scene = create_main_menu();
    scene->display = 0;

    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == 0) {
        scene->handle_event(scene, game, window);
        frames += 1;
        if (frames >= (game->window->framerate / 30.0)) {
            update_objects(scene, scene->objects_list, game);
            frames -= game->window->framerate / 30.0;
        }
        display_scene(scene, window);
        draw_cursor(game->cursor, window);
        sfRenderWindow_display(window);
    }
    return (scene->display);
}

int game_loop(game_t *game, sfRenderWindow *window)
{
    int frames = 0;
    scene_t *scene = init_game_scene(game, game->map);

    while (sfRenderWindow_isOpen(window)) {
        scene->handle_event(scene, game, window);
        frames += 1;
        if (frames >= (game->window->framerate / 30.0)) {
            update_objects(scene, scene->objects_list, game);
            increase_score(game);
            frames -= game->window->framerate / 30.0;
        }
        display_scene(scene, window);
        sfRenderWindow_drawText(window, game->score->text, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}