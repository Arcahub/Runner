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
    TEXT_BUTTON,
    BAR,
    DECOR,
    EFFECT,
    TRAP,
    CHUNK,
    FlEUR,
    INFO
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

////////////////////////////////////////////////////////////
/// \brief Initialize game_object frame
///
/// Initialize game_object frame to the first frame of the frames keys of his actual state
///
/// \param game_object_t object to initialize
////////////////////////////////////////////////////////////
void init_game_object_frame(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object frame
///
/// Update game_object frame to the next frame in the frames keys of his actual 
/// state and his is already at the last depending on the value of the loop bool it will start from start or won't change the actual frame
///
/// \param game_object_t object to update
////////////////////////////////////////////////////////////
void update_game_object_frame(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object frame
///
/// Update game_object frame to the previous frame in the frames keys of his actual
/// state and his is already at the first depending on the value of the loop bool it will stop
///
/// \param game_object_t object to update
////////////////////////////////////////////////////////////
void update_game_object_frame_reversed(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object state
///
/// Change game_object state and update his frame keys
///
/// \param game_object_t object to update
/// \param int state the new state of the object
////////////////////////////////////////////////////////////
void update_game_object_state(struct game_object *object , int state);

////////////////////////////////////////////////////////////
/// \brief Create a game_object
///
/// Create and initialize a gameobject with a sprite, a texture, a position and a type.
///
/// \param game_object_t last_object of the linked list
/// \param string path of the texture of the object
/// \param vector pos of the sprite
/// \param object_type type of the game_object
///
/// \return game_object_t *object
////////////////////////////////////////////////////////////
struct game_object *create_game_object(struct game_object *last, char *path, \
sfVector2f pos, object_type type);

////////////////////////////////////////////////////////////
/// \brief Initialize a game_object
///
/// Simply make pointeur equal to NULL and initialize value to zero
///
/// \param game_object_t object to initialize
////////////////////////////////////////////////////////////
void init_game_object(game_object_t *object);
void move_object(game_object_t *);
void draw_objects(game_object_t *, sfRenderWindow *, int);
void update_objects(scene_t *, game_object_t *, game_t *);
void destroy_object_list(scene_t *);
void destroy_game_object(scene_t *, game_object_t *, game_object_t *);
void is_click_on_object(scene_t *, sfMouseButtonEvent, game_t *);

void init_appearing_object(game_object_t *);
bool update_appearing_object(game_object_t *, scene_t *);
void update_disappearing_object(game_object_t *);

game_object_t *create_animated_object(game_object_t *, char *, sfVector2f, \
sfIntRect **);
#endif /* !GAME_OBJECT_H_ */