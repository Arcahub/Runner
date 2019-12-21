/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game
*/

#include "my_runner.h"
#include <stdlib.h>
#include <SFML/Audio.h>

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
    game->scene_loop[MAIN_MENU_SCENE] = &main_menu_loop;
    game->scene_loop[GAME_SCENE] = &game_loop;
    game->scene_loop[OPTION_SCENE] = &options_loop;
    return(game);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free(game->map);
    sfFont_destroy((sfFont *)sfText_getFont(game->score->text));
    sfText_destroy(game->score->text);
    free(game->score);
    sfSprite_destroy(game->cursor.sprite);
    sfTexture_destroy(game->cursor.texture);
    free(game);
}