/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** main
*/

#include "define.h"
#include "my_graph.h"
#include "my_runner.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

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
    window->window = make_window(window, sfFullscreen);
    return (window);
}

int my_runner(int argc, char **argv)
{
    char *map = read_map(argv[1]);
    game_t *game = init_game(map);
    sfRenderWindow *window = NULL;
    sfMusic *music = sfMusic_createFromFile("templates/sounds/Hollow_Knight_Ambience_Main_Menu_Theme.ogg");
    int display = MAIN_MENU_SCENE;

    if (music == NULL || game == NULL)
        return (84);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    window  = game->window->window;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        display = game->scene_loop[display](game, window);
    }
    destroy_game(game);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    return (0);
}

int main(int argc, char **argv, char **env)
{
    bool has_display = false;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp(env[i], "DISPLAY"))
            has_display = true;
    if (has_display == false)
        return (84);
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "DESCRIPTION:\n\t./my_runner MAP\n\nUSAGE:\n\tMAP : path to the map in tile mapping\n", 78);
        return (0);
    }
    return (my_runner(argc, argv));
}