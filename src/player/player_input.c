/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** player_input
*/

#include "my_runner.h"

void player_input_space(game_t *game)
{
    if (game->player->move.y == 0 && game->player->state == RUNNING) {
        game->player->move.y = - JUMP_SPEED;
        update_game_object_state(game->player, JUMPING);
    }
    if (game->player->state == FALLING) {
        game->player->move.y = - JUMP_SPEED;
        game->player->pos.x -= PLAYER_DOUBLE_JUMPING_OFFSET;
        update_game_object_state(game->player, DOUBLE_JUMPING);
    }
}

void player_input_a(game_t *game)
{
    if (game->player->pos.x == PLAYER_START_X) {
        game->player->move.x += 50;
        update_game_object_state(game->player, DASHING);
    }
}

void player_input_x(game_t *game)
{
    if (game->player->state != ATTACKING_RIGHT) {
        game->player->pos.x -= PLAYER_ATTACKING_RIGHT_OFFSET;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        update_game_object_state(game->player, ATTACKING_RIGHT);
    }
}

void player_input(game_t *game, sfKeyCode key)
{
    switch (key) {
    case sfKeySpace:
        player_input_space(game);
        break;
    case sfKeyA:
        player_input_a(game);
        break;
    case sfKeyX:
        player_input_x(game);
        break;
    }
}