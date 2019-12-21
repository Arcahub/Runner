/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** const
*/

#include <SFML/Graphics.h>

#ifndef CONST_H
#define CONST_H

// WINDOW

static const unsigned short int WINDOW_WIDTH = 1920;
static const unsigned short int WINDOW_HEIGHT = 1000;
static const unsigned char WINDOW_BITS_PER_PIXEL = 32;
static const unsigned char WINDOW_FRAMERATE = 60;
static const char *WINDOW_NAME = "My Runner";

static const sfColor GAME_BACKGROUND_COLOR = {66, 98, 116, 0};

// FRAMERATE

static const float MAX_FRAME_RANGE = 0.25;
static const float DELAY_BETWEEN_UPDATE = 1 / 30.0;
static const float SECOND_IN_MICRO = 1000000.0;

// PLAYER

static const unsigned int PLAYER_START_X = 100;
static const unsigned int PLAYER_START_Y = 800;
static const unsigned char PLAYER_SPEED_X = 0;
static const unsigned char PLAYER_MAX_SPEED_X = 2;
static const unsigned char PLAYER_SPEED_Y = 0;
static const char *PLAYER_SPRITE_PATH = "templates/mobs/player/knight_sprite_sheets.png";
static const sfIntRect *PLAYER_RUNNING_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 75, 130},
    &(sfIntRect){0, 0, 75, 130},
    &(sfIntRect){75, 0, 75, 130},
    &(sfIntRect){75, 0, 75, 130},
    &(sfIntRect){150, 0, 75, 130},
    &(sfIntRect){150, 0, 75, 130},
    &(sfIntRect){225, 0, 75, 130},
    &(sfIntRect){225, 0, 75, 130},
    &(sfIntRect){300, 0, 75, 130},
    &(sfIntRect){300, 0, 75, 130},
    &(sfIntRect){375, 0, 75, 130},
    &(sfIntRect){375, 0, 75, 130},
    NULL};
static const char *PLAYER_RUNNING_SOUND_PATH = "templates/sounds/hero_run_footsteps_stone.ogg";
static const sfIntRect *PLAYER_JUMPING_FRAME_KEYS[] = {
    &(sfIntRect){0, 130, 75, 130},
    NULL};
static const char *PLAYER_JUMPING_SOUND_PATH = "templates/sounds/hero_jump.ogg";
static const sfIntRect *PLAYER_FALLING_FRAME_KEYS[] = {
    &(sfIntRect){0, 260, 90, 130},
    &(sfIntRect){0, 260, 90, 130},
    &(sfIntRect){90, 260, 90, 130},
    &(sfIntRect){90, 260, 90, 130},
    &(sfIntRect){180, 260, 90, 130},
    &(sfIntRect){180, 260, 90, 130},
    &(sfIntRect){270, 260, 90, 130},
    &(sfIntRect){270, 260, 90, 130},
    NULL
};
static const char *PLAYER_FALLING_SOUND_PATH = "templates/sounds/hero_falling.ogg";

static const unsigned char PLAYER_DASH_OFFSET = 95;
static const char *PLAYER_DASHING_SOUND_PATH = "templates/sounds/hero_dash.ogg";
static const sfIntRect *PLAYER_DASHING_FRAME_KEYS[] = {
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    NULL
};

static const unsigned char PLAYER_ATTACKING_RIGHT_OFFSET = 55;
static const char *PLAYER_ATTACKING_SOUND_PATH = "templates/sounds/sword_1.ogg";
static const sfIntRect *PLAYER_ATTACKING_RIGHT_FRAME_KEYS[] = {
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    NULL
};

static const unsigned char PLAYER_DOUBLE_JUMPING_OFFSET = 55;
static const sfIntRect *PLAYER_DOUBLE_JUMPING_FRAME_KEYS[] = {
    &(sfIntRect){0, 650, 130, 130},
    &(sfIntRect){0, 650, 130, 130},
    &(sfIntRect){0, 650, 130, 130},
    &(sfIntRect){130, 650, 130, 130},
    &(sfIntRect){130, 650, 130, 130},
    &(sfIntRect){130, 650, 130, 130},
    &(sfIntRect){260, 650, 130, 130},
    &(sfIntRect){260, 650, 130, 130},
    &(sfIntRect){260, 650, 130, 130},
    NULL};
static const char *PLAYER_DOUBLE_JUMPING_SOUND_PATH = "templates/sounds/hero_wings.ogg";

// MAIN MENU

static const unsigned short TITLE_X = (WINDOW_WIDTH - 1274) / 2;
static const unsigned short TITLE_Y = 0;

static const sfIntRect *BUTTON_UNSELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 396, 267, 36},
    &(sfIntRect){0, 360, 267, 36},
    &(sfIntRect){0, 324, 267, 36},
    &(sfIntRect){0, 288, 267, 36},
    &(sfIntRect){0, 252, 267, 36},
    &(sfIntRect){0, 216, 267, 36},
    &(sfIntRect){0, 180, 267, 36},
    &(sfIntRect){0, 144, 267, 36},
    &(sfIntRect){0, 108, 267, 36},
    &(sfIntRect){0, 72, 267, 36},
    &(sfIntRect){0, 36, 267, 36},
    &(sfIntRect){0, 0, 267, 36},
    NULL};

static const sfIntRect *BUTTON_SELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 267, 36},
    &(sfIntRect){0, 36, 267, 36},
    &(sfIntRect){0, 72, 267, 36},
    &(sfIntRect){0, 108, 267, 36},
    &(sfIntRect){0, 144, 267, 36},
    &(sfIntRect){0, 180, 267, 36},
    &(sfIntRect){0, 216, 267, 36},
    &(sfIntRect){0, 252, 267, 36},
    &(sfIntRect){0, 288, 267, 36},
    &(sfIntRect){0, 324, 267, 36},
    &(sfIntRect){0, 360, 267, 36},
    &(sfIntRect){0, 396, 267, 36},
    NULL};

static const unsigned short PLAY_BUTTON_X = (WINDOW_WIDTH - 206) / 2;
static const unsigned short PLAY_BUTTON_Y = 700;
static const unsigned short OPTION_BUTTON_X = (WINDOW_WIDTH - 267) / 2;
static const unsigned short OPTION_BUTTON_Y = 800;
static const unsigned short EXIT_BUTTON_X = (WINDOW_WIDTH - 196) / 2;
static const unsigned short EXIT_BUTTON_Y = 900;

static sfVector2i MAIN_MENU_COORDS[] = {
    (const sfVector2i){960, 718},
    (const sfVector2i){960, 818},
    (const sfVector2i){960, 918}
};

// PHYSICS

static const float JUMP_SPEED = 35.0;
static const float JUMP_SPEED_MIN = 5.0;
static const float FALLING_MAX_SPEED = 25.0;
static const float GRAVITY = 2.0;

// OPTIONS
static const char *BAR_PATH = "templates/menu/bar.png";
static const char *BAR_BACKGROUND_PATH = "templates/menu/bar_background.png";
static const unsigned short BAR_WIDTH = 500;
static const unsigned short BAR_HEIGHT = 10;
static const unsigned char BAR_BOX_OFFSET = 20;
static const unsigned short VOLUME_BAR_X = (WINDOW_WIDTH - BAR_WIDTH) / 2;
static const unsigned short VOLUME_BAR_Y = 400;

static const unsigned char VOLUME_UNIT = 10;
static const unsigned char MAX_VOLUME = 100;
static const unsigned char MIN_VOLUME = 0;

static const char *INDICATOR_PATH = "templates/menu/scrollbar_fleur_new.png";
static const unsigned short INDICATOR_WIDTH = 107;
static const unsigned short INDICATOR_X = VOLUME_BAR_X;
static const unsigned short INDICATOR_Y = 400 - 25;

static const char *FONT_PATH= "templates/font/arial.ttf";
static const char *CURSOR_PATH = "templates/menu/Cursor.png";
#endif