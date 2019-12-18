/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** main
*/

#include "my_graph.h"
#include "my_runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
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
    game->map = map;
    init_score(game);
    game->cursor = init_cursor((char *)CURSOR_PATH);
    if (game->window == NULL || game->score == NULL)
        return (NULL);
    game->scene_loop[0] = &main_menu_loop;
    game->scene_loop[1] = &game_loop;
    return(game);
}

int my_runner(int argc, char **argv)
{
    char *map = read_map(argv[1]);
    game_t *game = init_game(map);
    sfRenderWindow *window = NULL;
    sfMusic *music = sfMusic_createFromFile("templates/sounds/Hollow_Knight_Ambience_Main_Menu_Theme.ogg");
    int display = 0;

    if (music == NULL || game == NULL)
        return (84);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    window  = game->window->window;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        display = game->scene_loop[display](game, window);
    }
    sfMusic_destroy(music);
}

int main(int argc, char **argv, char **env)
{
    return (my_runner(argc, argv));
}