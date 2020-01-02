/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;

typedef struct scene {
    void (*handle_event)(struct scene *, struct game *, sfRenderWindow *);
    game_object_t *objects_list;
    sfColor background_color;
    int z_index_deepth;
    int display;
    int joystick_coord_id;
    sfRenderWindow *window;
} scene_t;

void display_scene(scene_t *, sfRenderWindow *);
void destroy_scene(scene_t *);

#endif /* !SCENE_H_ */
