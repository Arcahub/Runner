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

void get_highscore(game_t *game, score_t *score)
{
    char **res = NULL;

    if (game->mysql == NULL) {
        score->score = 0;
        return;
    }
    res = make_select_query(game->mysql, "scores", 1, "*");
    if (res != NULL) {
        score->score = 0;
        return;
    }
    for (int i = 0; res[i]; i++) {
        for (int j = 0; res[i][j]; j++)
            printf("%d\n", my_nbr_to_str(res[i][j]));
    }

}

void init_highscore(game_t *game)
{
    score_t *score = NULL;

    score = malloc(sizeof(score_t));
    game->highscore = score;
    game->mysql = make_mysql("arcarox.online", "runner", "passrunner", "runner");
    if (score == NULL)
        return;
    get_highscore(game, score);
    score->score_text = my_strcat((char *)BASE_HIGHSCORE, \
    my_nbr_to_str(score->score));
    score->text = init_text(score->score_text, 0, 50, (char *) FONT_PATH);
}

void init_score(game_t *game)
{
    score_t *score = NULL;

    score = malloc(sizeof(score_t));
    game->score = score;
    if (score == NULL)
        return;
    score->score = 0;
    score->score_text = my_strcat((char *)BASE_SCORE, my_nbr_to_str(0));
    score->text = init_text(score->score_text, 0, 0, (char *) FONT_PATH);
}

void increase_score(game_t *game)
{
    game->score->score += 1;
    free (game->score->score_text);
    game->score->score_text = \
    my_strcat((char *)BASE_SCORE, my_nbr_to_str(game->score->score));
    sfText_setString(game->score->text, game->score->score_text);
    if (game->score > game->highscore->score) {
        game->highscore->score = game->score->score;
        free (game->highscore->score_text);
        game->highscore->score_text = \
        my_strcat((char *)BASE_HIGHSCORE, \
        my_nbr_to_str(game->highscore->score));
        sfText_setString(game->highscore->text, game->highscore->score_text);
    }
}