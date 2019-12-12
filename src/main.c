/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** main
*/

#include "my_graph.h"
#include "my_runner.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->width = WINDOW_WIDTH;
    window->height = WINDOW_HEIGHT;
    window->bits = WINDOW_BITS_PER_PIXEL;
    window->framerate = WINDOW_FRAMERATE;
    window->name = (char *)WINDOW_NAME;
    window->window = make_window(window, sfFullscreen);
    return (window);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = init_window();
    init_scenes(game);
    return(game);
}

int my_runner(void)
{
    game_t *game = init_game();
    sfRenderWindow *window = game->window->window;
    int frames = 0;

    while (sfRenderWindow_isOpen(window)) {
        game->scene_list[0]->handle_event(game, window);
        frames += 1;
        if (frames >= (game->window->framerate / 30.0)) {
            update_objects(game->scene_list[0]->objects_list, game);
            frames = 0;
        }
        display_scene(game->scene_list[0], window);
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv, char **env)
{
    return (my_runner());
}