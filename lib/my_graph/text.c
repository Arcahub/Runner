/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** text
*/

#include "my_graph.h"
#include <stdlib.h>

sfText *init_text(char *str, int x, int y, char *font_path)
{
    sfVector2f vector = {x, y};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_path);

    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 32);
    sfText_setPosition(text, vector);
    sfText_setColor(text, sfWhite);
    sfText_setStyle(text, sfTextBold);
    return (text);
}