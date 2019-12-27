/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** loop
*/

#include "my_runner.h"

int main_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_main_menu();
    scene->display = MAIN_MENU_SCENE;
    scene_index display = MAIN_MENU_SCENE;

    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == MAIN_MENU_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_main_menu(scene, game, window);
    }
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int options_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = init_options_scene(game);
    int display = GAME_SCENE;

    while (sfRenderWindow_isOpen(window) && scene->display == OPTION_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_options(scene, game, window);
    }
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int game_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = init_game_scene(game, game->map);
    scene->display = GAME_SCENE;
    int display = GAME_SCENE;

    while (sfRenderWindow_isOpen(window) && scene->display == GAME_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_game(scene, game, window);
    }
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}