/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** score
*/

#include "my_runner.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void init_score(game_t *game)
{
    score_t *score = NULL;

    score = malloc(sizeof(score_t));
    game->score = score;
    if (score == NULL)
        return;
    score->score = 0;
    score->text = init_text("Score : 0", 0, 0, (char *) FONT_PATH);
}

void increase_score(game_t *game)
{
    game->score->score += 1;
    sfText_setString(game->score->text, \
    my_strcat("Score : ", my_nbr_to_str(game->score->score)));
}