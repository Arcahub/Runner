/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

typedef struct game game_t;
typedef struct scene scene_t;
typedef struct anim anim_t;

typedef struct anim {
    sfIntRect **frames_key;
    sfSoundBuffer *sound_buffer;
    bool sound_loop;
    bool loop;
    int frame_id;
    int restart_id;
} anim_t;

typedef enum {
    PLAYER,
    PARALLAX,
    SOLID,
    BUTTON,
    BAR,
    DECOR,
    EFFECT,
    TRAP,
    CHUNK
} object_type;

typedef struct game_object {
    sfTexture *texture;
    sfSprite *sprite;
    sfColor sprite_color;
    sfSound *sound_effect;
    sfVector2f pos;
    sfVector2f last_pos;
    int z_index;
    sfIntRect box;
    sfVector2f move;
    anim_t *anim;
    int state;
    object_type type;
    sfClock *delta_t;
    bool (*update)(struct game_object *, struct scene *);
    void (*callback)(struct game_object *, void *);
    struct game_object *next;
} game_object_t;

void update_game_object_state(struct game_object *, int);
void init_game_object_frame(struct game_object *);
struct game_object *create_game_object(struct game_object *, char *, \
sfVector2f, object_type);
void init_game_object(game_object_t *);
void update_game_object_frame(struct game_object *);
void move_object(game_object_t *);
void draw_objects(game_object_t *, sfRenderWindow *, int);
void update_objects(scene_t *, game_object_t *, game_t *);
void destroy_object_list(scene_t *);
void destroy_game_object(scene_t *, game_object_t *, game_object_t *);
void is_click_on_object(scene_t *, sfMouseButtonEvent, game_t *, object_type);

void init_appearing_object(game_object_t *);
bool update_appearing_object(game_object_t *, scene_t *);
void update_disappearing_object(game_object_t *);

game_object_t *create_animated_object(game_object_t *, char *, sfVector2f, \
sfIntRect **);
#endif /* !GAME_OBJECT_H_ */