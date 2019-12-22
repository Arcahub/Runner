/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** define
*/



#ifndef DEFINE_H_
#define DEFINE_H_

#include <SFML/Graphics.h>

// WINDOW

const unsigned short int WINDOW_WIDTH = 1920;
const unsigned short int WINDOW_HEIGHT = 1000;
const unsigned char WINDOW_BITS_PER_PIXEL = 32;
const unsigned char WINDOW_FRAMERATE = 60;
const char *WINDOW_NAME = "My Runner";

const sfColor GAME_BACKGROUND_COLOR = {66, 98, 116, 0};

// FRAMERATE

const float MAX_FRAME_RANGE = 0.25;
const float DELAY_BETWEEN_UPDATE = 1 / 30.0;
const float SECOND_IN_MICRO = 1000000.0;

// PLAYER

const unsigned int PLAYER_START_X = 100;
const unsigned int PLAYER_START_Y = 800;
const unsigned char PLAYER_SPEED_X = 0;
const unsigned char PLAYER_MAX_SPEED_X = 2;
const unsigned char PLAYER_SPEED_Y = 0;
const char *PLAYER_SPRITE_PATH = "templates/mobs/player/knight_sprite_sheets.png";
const sfIntRect *PLAYER_RUNNING_FRAME_KEYS[] = {
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
const char *PLAYER_RUNNING_SOUND_PATH = "templates/sounds/hero_run_footsteps_stone.ogg";
const sfIntRect *PLAYER_JUMPING_FRAME_KEYS[] = {
    &(sfIntRect){0, 130, 75, 130},
    NULL};
const char *PLAYER_JUMPING_SOUND_PATH = "templates/sounds/hero_jump.ogg";
const sfIntRect *PLAYER_FALLING_FRAME_KEYS[] = {
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
const char *PLAYER_FALLING_SOUND_PATH = "templates/sounds/hero_falling.ogg";

const unsigned char PLAYER_DASH_OFFSET = 95;
const char *PLAYER_DASHING_SOUND_PATH = "templates/sounds/hero_dash.ogg";
const sfIntRect *PLAYER_DASHING_FRAME_KEYS[] = {
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    &(sfIntRect){0, 520, 170, 130},
    NULL
};

const unsigned char PLAYER_ATTACKING_RIGHT_OFFSET = 55;
const char *PLAYER_ATTACKING_SOUND_PATH = "templates/sounds/sword_1.ogg";
const sfIntRect *PLAYER_ATTACKING_RIGHT_FRAME_KEYS[] = {
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    &(sfIntRect){0, 390, 130, 130},
    NULL
};

const unsigned char PLAYER_DOUBLE_JUMPING_OFFSET = 55;
const sfIntRect *PLAYER_DOUBLE_JUMPING_FRAME_KEYS[] = {
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
const char *PLAYER_DOUBLE_JUMPING_SOUND_PATH = "templates/sounds/hero_wings.ogg";

// MAIN MENU

const unsigned short TITLE_X = (WINDOW_WIDTH - 1274) / 2;
const unsigned short TITLE_Y = 0;

const sfIntRect *BUTTON_UNSELECTED_FRAME_KEYS[] = {
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

const sfIntRect *BUTTON_SELECTED_FRAME_KEYS[] = {
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

const unsigned short PLAY_BUTTON_X = (WINDOW_WIDTH - 206) / 2;
const unsigned short PLAY_BUTTON_Y = 700;
const unsigned short OPTION_BUTTON_X = (WINDOW_WIDTH - 267) / 2;
const unsigned short OPTION_BUTTON_Y = 800;
const unsigned short EXIT_BUTTON_X = (WINDOW_WIDTH - 196) / 2;
const unsigned short EXIT_BUTTON_Y = 900;

const sfVector2i MAIN_MENU_COORDS[] = {
    {960, 718},
    {960, 818},
    {960, 918}
};

// PHYSICS

const float JUMP_SPEED = 35.0;
const float JUMP_SPEED_MIN = 5.0;
const float FALLING_MAX_SPEED = 25.0;
const float GRAVITY = 2.0;

// OPTIONS
const char *BAR_PATH = "templates/menu/bar.png";
const char *BAR_BACKGROUND_PATH = "templates/menu/bar_background.png";
const unsigned short BAR_WIDTH = 500;
const unsigned short BAR_HEIGHT = 10;
const unsigned char BAR_BOX_OFFSET = 20;
const unsigned short VOLUME_BAR_X = (WINDOW_WIDTH - BAR_WIDTH) / 2;
const unsigned short VOLUME_BAR_Y = 400;

const unsigned char VOLUME_UNIT = 10;
const unsigned char MAX_VOLUME = 100;
const unsigned char MIN_VOLUME = 0;

const char *INDICATOR_PATH = "templates/menu/scrollbar_fleur_new.png";
const unsigned short INDICATOR_WIDTH = 107;
const unsigned short INDICATOR_X = VOLUME_BAR_X;
const unsigned short INDICATOR_Y = 400 - 25;

const char *FONT_PATH= "templates/font/arial.ttf";
const char *CURSOR_PATH = "templates/menu/Cursor.png";

#endif /* !DEFINE_H_ */
