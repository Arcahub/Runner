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

    if (window == NULL)
        return (NULL);
    window->width = WINDOW_WIDTH;
    window->height = WINDOW_HEIGHT;
    window->bits = WINDOW_BITS_PER_PIXEL;
    window->framerate = WINDOW_FRAMERATE;
    window->name = (char *)WINDOW_NAME;
    window->window = make_window(window, sfClose);
    return (window);
}

game_t *init_game(char *map)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL || map == NULL)
        return (NULL);
    game->window = init_window();
    if (game->window == NULL)
        return (NULL);
    init_scenes(game, map);
    return(game);
}

int my_runner(int argc, char **argv)
{
    char *map = read_map(argv[1]);
    game_t *game = init_game(map);
    sfRenderWindow *window = NULL;
    int frames = 0;

    if (game == NULL)
        return (84);
    window  = game->window->window;
    while (sfRenderWindow_isOpen(window)) {
        game->scene_list[0]->handle_event(game, window);
        frames += 1;
        if (frames >= (game->window->framerate / 30.0)) {
            update_objects(game->scene_list[0], game->scene_list[0]->objects_list, game);
            frames -= game->window->framerate / 30.0;
        }
        display_scene(game->scene_list[0], window);
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv, char **env)
{
    return (my_runner(argc, argv));
}