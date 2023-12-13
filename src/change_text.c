/*
** EPITECH PROJECT, 2023
** change text value
** File description:
** change_text
*/
#include "../includes/my.h"
#include <stdio.h>

char *write_text_into_char(char *src, int len_nbr)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + len_nbr + 3));
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';
    return result;
}

void change_life_value(game_t game)
{
    int len;
    char *src_result;
    char *src;

    len = my_stock_len(game.stat.nbr_life);
    src = malloc(sizeof(char) * (len + 1));
    src[0] = '\0';
    my_stock_nbr(game.stat.nbr_life, src);
    src_result = write_text_into_char("REMAINING LIVES: ", len);
    my_strcat(src_result, src);
    sfText_setString(game.stat.life, src_result);
    free(src);
    free(src_result);
}

void change_score_value(game_t game)
{
    int len = my_stock_len(game.stat.nbr_kill);
    char *src;
    char *src_result;

    src = malloc(sizeof(char) * (len + 1));
    src[0] = '\0';
    my_stock_nbr(game.stat.nbr_kill, src);
    src_result = write_text_into_char("SCORE: ", len);
    my_strcat(src_result, src);
    sfText_setString(game.stat.score, src_result);
    free(src);
    free(src_result);
}

void change_high_score_value(game_t game)
{
    int len = my_stock_len(game.stat.nbr_score_max);
    char *src;
    char *src_result;

    src = malloc(sizeof(char) * (len + 1));
    src[0] = '\0';
    my_stock_nbr(game.stat.nbr_score_max, src);
    src_result = write_text_into_char("HIGH SCORE: ", len);
    my_strcat(src_result, src);
    sfText_setString(game.stat.high_score, src_result);
    free(src);
    free(src_result);
}
