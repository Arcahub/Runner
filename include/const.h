/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** const
*/

#include <SFML/Graphics.h>

#ifndef CONST_H
#define CONST_H

static const unsigned short int WINDOW_WIDTH = 1920;
static const unsigned short int WINDOW_HEIGHT = 1000;
static const unsigned char WINDOW_BITS_PER_PIXEL = 32;
static const unsigned char WINDOW_FRAMERATE = 60;
static const char *WINDOW_NAME = "My Runner";

static const sfColor GAME_BACKGROUND_COLOR = {66, 98, 116, 0};

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

static const sfIntRect *BUTTON_UNSELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 792, 413, 72},
    &(sfIntRect){0, 720, 413, 72},
    &(sfIntRect){0, 648, 413, 72},
    &(sfIntRect){0, 576, 413, 72},
    &(sfIntRect){0, 504, 413, 72},
    &(sfIntRect){0, 432, 413, 72},
    &(sfIntRect){0, 360, 413, 72},
    &(sfIntRect){0, 288, 413, 72},
    &(sfIntRect){0, 216, 413, 72},
    &(sfIntRect){0, 144, 413, 72},
    &(sfIntRect){0, 72, 413, 72},
    &(sfIntRect){0, 0, 413, 72},
    NULL};

static const sfIntRect *BUTTON_SELECTED_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 413, 72},
    &(sfIntRect){0, 72, 413, 72},
    &(sfIntRect){0, 144, 413, 72},
    &(sfIntRect){0, 216, 413, 72},
    &(sfIntRect){0, 288, 413, 72},
    &(sfIntRect){0, 360, 413, 72},
    &(sfIntRect){0, 432, 413, 72},
    &(sfIntRect){0, 504, 413, 72},
    &(sfIntRect){0, 576, 413, 72},
    &(sfIntRect){0, 648, 413, 72},
    &(sfIntRect){0, 720, 413, 72},
    &(sfIntRect){0, 792, 413, 72},
    NULL};

static const float JUMP_SPEED = 35.0;
static const float JUMP_SPEED_MIN = 5.0;
static const float FALLING_MAX_SPEED = 25.0;
static const float GRAVITY = 2.0;
#endif