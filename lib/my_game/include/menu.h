/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

typedef struct game_object game_object_t;
typedef struct scene scene_t;
typedef struct game game_t;

typedef enum {
    SELECTED,
    UNSELECTED
} button_state;

game_object_t *create_text_button(game_object_t *, char *, sfVector2f);
game_object_t *create_button(game_object_t *, char *, sfVector2f, sfIntRect **);

#endif /* !MENU_H_ */
