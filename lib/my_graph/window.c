/*
** EPITECH PROJECT, 2019
** init_bootstrap
** File description:
** window
*/

#include <SFML/Graphics.h>
#include "my_graph.h"

sfRenderWindow *make_window(window_t *window, sfUint32 style)
{
    sfVideoMode mode = {window->width, window->height, window->bits};
    sfRenderWindow *window_render = NULL;
    size_t *count = NULL;

    if (style == sfFullscreen)
        mode = sfVideoMode_getFullscreenModes(count)[0];
    window_render = sfRenderWindow_create(mode, window->name, style, NULL);
    if (window_render == NULL)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window_render, window->framerate);
    return (window_render);
}