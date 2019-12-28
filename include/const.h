/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** const
*/

#include <SFML/Graphics.h>

#ifndef CONST_H
#define CONST_H

// ENV

extern const char *ENV_DISPLAY;

// USAGE

extern const char *USAGE_FLAG;
extern const char *USAGE;

// WINDOW

extern const unsigned short int WINDOW_WIDTH;
extern const unsigned short int WINDOW_HEIGHT;
extern const unsigned char WINDOW_BITS_PER_PIXEL;
extern const unsigned char WINDOW_FRAMERATE;
extern const char *WINDOW_NAME;

extern const sfColor GAME_BACKGROUND_COLOR;

// MUSIC

extern const char *MENU_MUSIC_PATH;

// SCORE

extern const char *BASE_SCORE;

// FRAMERATE

extern const float MAX_FRAME_RANGE;
extern const float DELAY_BETWEEN_UPDATE;
extern const float SECOND_IN_MICRO;

// PLAYER

extern const unsigned int PLAYER_START_X;
extern const unsigned int PLAYER_START_Y;
extern const unsigned char PLAYER_SPEED_X;
extern const unsigned char PLAYER_MAX_SPEED_X;
extern const unsigned char PLAYER_SPEED_Y;
extern const char *PLAYER_SPRITE_PATH;
extern const sfIntRect *PLAYER_RUNNING_FRAME_KEYS[];
extern const char *PLAYER_RUNNING_SOUND_PATH;
extern const sfIntRect *PLAYER_JUMPING_FRAME_KEYS[];
extern const char *PLAYER_JUMPING_SOUND_PATH;
extern const sfIntRect *PLAYER_FALLING_FRAME_KEYS[];
extern const char *PLAYER_FALLING_SOUND_PATH;

extern const unsigned char PLAYER_DASH_OFFSET;
extern const unsigned char PLAYER_DASH_SPEED;
extern const char *PLAYER_DASHING_SOUND_PATH;
extern const sfIntRect *PLAYER_DASHING_FRAME_KEYS[];

extern const char *PLAYER_ATTACKING_SOUND_PATH;

extern const unsigned char PLAYER_ATTACKING_RIGHT_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_RIGHT_FRAME_KEYS[];

extern const unsigned char PLAYER_ATTACKING_TOP_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_TOP_FRAME_KEYS[];

extern const unsigned char PLAYER_ATTACKING_DOWN_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_DOWN_FRAME_KEYS[];

extern const char *ATTACK_EFFECT_PATH;
extern const sfIntRect *RIGHT_ATTACK_EFFECT_FRAME_KEYS[];
extern const sfIntRect *TOP_ATTACK_EFFECT_FRAME_KEYS[];
extern const sfIntRect *DOWN_ATTACK_EFFECT_FRAME_KEYS[];

extern const unsigned char TOP_ATTACK_EFFECT_OFFSET;

extern const unsigned char PLAYER_DOUBLE_JUMPING_OFFSET;
extern const sfIntRect *PLAYER_DOUBLE_JUMPING_FRAME_KEYS[];
extern const char *PLAYER_DOUBLE_JUMPING_SOUND_PATH;

// MAIN MENU

extern const unsigned short TITLE_X;
extern const unsigned short TITLE_Y;
extern const char *TITLE_PATH;

extern const sfIntRect *BUTTON_UNSELECTED_FRAME_KEYS[];
extern const sfIntRect *BUTTON_SELECTED_FRAME_KEYS[];

extern const char *BUTTON_SOUND_PATH;

extern const unsigned short PLAY_BUTTON_X;
extern const unsigned short PLAY_BUTTON_Y;
extern const char *PLAY_BUTTON_PATH;
extern const unsigned short OPTION_BUTTON_X;
extern const unsigned short OPTION_BUTTON_Y;
extern const char *OPTION_BUTTON_PATH;
extern const unsigned short EXIT_BUTTON_X;
extern const unsigned short EXIT_BUTTON_Y;
extern const char *EXIT_BUTTON_PATH;

extern const sfVector2i MAIN_MENU_COORDS[];

// PHYSICS

extern const float JUMP_SPEED;
extern const float JUMP_SPEED_MIN;
extern const float FALLING_MAX_SPEED;
extern const float GRAVITY;

// OPTIONS
extern const char *BAR_PATH;
extern const char *BAR_BACKGROUND_PATH;
extern const unsigned short BAR_WIDTH;
extern const unsigned short BAR_HEIGHT;
extern const unsigned char BAR_BOX_OFFSET;
extern const unsigned short VOLUME_BAR_X;
extern const unsigned short VOLUME_BAR_Y;

extern const unsigned char VOLUME_UNIT;
extern const unsigned char MAX_VOLUME;
extern const unsigned char MIN_VOLUME;

extern const char *INDICATOR_PATH;
extern const unsigned short INDICATOR_WIDTH;
extern const unsigned short INDICATOR_X;
extern const unsigned short INDICATOR_Y;

extern const char *FONT_PATH;
extern const char *CURSOR_PATH;

// PARALLAX SPEED

extern const char PARALLAX_SPEED_2;
extern const char PARALLAX_SPEED_3;
extern const char PARALLAX_SPEED_4;
extern const char PARALLAX_SPEED_5;
extern const char PARALLAX_SPEED_6;
extern const char PARALLAX_SPEED_8;
extern const char PLAYER_GROUND_SPEED;

// LEVEL DESIGN

extern const unsigned char TILE_WIDTH;
extern const unsigned char TILE_HEIGHT;
extern const unsigned char TILES_PER_CHUNK;
extern const unsigned short TILE_MAX_HEIGHT;

extern const unsigned char MAX_FLOOR_WIDTH;

extern const unsigned short CHUNK_WIDTH;
extern const unsigned short CHUNK_HEIGHT;

extern const char *GROUND_PATH;
extern const char *SPIKES_PATH;
#endif