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
static const sfIntRect *PLAYER_JUMPING_FRAME_KEYS[] = {
    &(sfIntRect){0, 130, 75, 130},
    NULL};
static const sfIntRect *PLAYER_FALLING_FRAME_KEYS[] = {
    &(sfIntRect){0, 260, 90, 130},
    &(sfIntRect){0, 260, 90, 130},
    &(sfIntRect){90, 260, 90, 130},
    &(sfIntRect){90, 260, 90, 130},
    &(sfIntRect){180, 260, 90, 130},
    &(sfIntRect){180, 260, 90, 130},
    &(sfIntRect){270, 260, 90, 130},
    &(sfIntRect){270, 260, 90, 130},
    NULL};

// MAIN MENU

static const sfIntRect *BUTTON_UNSELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 792, 533, 72},
    &(sfIntRect){0, 720, 533, 72},
    &(sfIntRect){0, 648, 533, 72},
    &(sfIntRect){0, 576, 533, 72},
    &(sfIntRect){0, 504, 533, 72},
    &(sfIntRect){0, 432, 533, 72},
    &(sfIntRect){0, 360, 533, 72},
    &(sfIntRect){0, 288, 533, 72},
    &(sfIntRect){0, 216, 533, 72},
    &(sfIntRect){0, 144, 533, 72},
    &(sfIntRect){0, 72, 533, 72},
    &(sfIntRect){0, 0, 533, 72},
    NULL};

static const sfIntRect *BUTTON_SELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 533, 72},
    &(sfIntRect){0, 72, 533, 72},
    &(sfIntRect){0, 144, 533, 72},
    &(sfIntRect){0, 216, 533, 72},
    &(sfIntRect){0, 288, 533, 72},
    &(sfIntRect){0, 360, 533, 72},
    &(sfIntRect){0, 432, 533, 72},
    &(sfIntRect){0, 504, 533, 72},
    &(sfIntRect){0, 576, 533, 72},
    &(sfIntRect){0, 648, 533, 72},
    &(sfIntRect){0, 720, 533, 72},
    &(sfIntRect){0, 792, 533, 72},
    NULL};

static const unsigned short PLAY_BUTTON_X = (WINDOW_WIDTH - 413) / 2;
static const unsigned short PLAY_BUTTON_Y = 300;
static const unsigned short OPTION_BUTTON_X = (WINDOW_WIDTH - 533) / 2;
static const unsigned short OPTION_BUTTON_Y = 500;
static const unsigned short EXIT_BUTTON_X = (WINDOW_WIDTH - 393) / 2;
static const unsigned short EXIT_BUTTON_Y = 700;

static sfVector2i MAIN_MENU_COORDS[] = {
    (const sfVector2i){960, 336},
    (const sfVector2i){960, 536},
    (const sfVector2i){960, 736}
};

// PHYSICS

static const float JUMP_SPEED = 35.0;
static const float JUMP_SPEED_MIN = 5.0;
static const float FALLING_MAX_SPEED = 25.0;
static const float GRAVITY = 2.0;

// OPTIONS
static const char *BAR_PATH = "templates/menu/bar.png";
static const char *BAR_BACKGROUND_PATH = "templates/menu/bar_background.png";
static const unsigned short VOLUME_BAR_Y = 400;
static const unsigned short VOLUME_BAR_X = 600;
static const unsigned short BAR_WIDTH = 500;
static const unsigned short BAR_HEIGHT = 10;
static const unsigned char BAR_BOX_OFFSET = 20;

static const unsigned char VOLUME_UNIT = 10;
static const unsigned char MAX_VOLUME = 100;
static const unsigned char MIN_VOLUME = 0;

static const char *INDICATOR_PATH = "templates/menu/scrollbar_fleur_new.png";
static const unsigned short INDICATOR_WIDTH = 107;
static const unsigned short INDICATOR_X = 600;
static const unsigned short INDICATOR_Y = 400 - 25;

static const char *FONT_PATH= "templates/font/arial.ttf";
static const char *CURSOR_PATH = "templates/menu/Cursor.png";
#endif