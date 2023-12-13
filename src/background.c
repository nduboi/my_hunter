/*
** EPITECH PROJECT, 2023
** fully_stock_datat_bird
** File description:
** bird
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/my.h"
#include "../includes/entity.h"
#include <stdio.h>
#include <SFML/Audio.h>

static void set_position_text(int x, int y, sfText *text)
{
    sfVector2f pos_text;

    pos_text.x = x;
    pos_text.y = y;
    sfText_setPosition(text, pos_text);
}

static game_t get_text(game_t game)
{
    sfFont *font = sfFont_createFromFile("design/scoreboard.ttf");

    set_position_text(40, 25, game.stat.life);
    sfText_setFont(game.stat.life, font);
    sfText_setCharacterSize(game.stat.life, 51);
    set_position_text(1625, 25, game.stat.score);
    sfText_setFont(game.stat.score, font);
    sfText_setCharacterSize(game.stat.score, 51);
    set_position_text(40, 945, game.stat.high_score);
    sfText_setFont(game.stat.high_score, font);
    sfText_setCharacterSize(game.stat.high_score, 51);
    return game;
}

static void set_newstring_from_int(sfText *text, int nbr)
{
    int len;
    char *src;

    len = my_stock_len(nbr);
    src = malloc(sizeof(char) * (len + 1));
    my_stock_nbr(nbr, src);
    sfText_setString(text, src);
    free(src);
}

static void change_high_score_value_init(sfText *text, int nbr)
{
    int len = my_stock_len(nbr);
    char *src;
    char *src_result;

    src = malloc(sizeof(char) * (len + 1));
    src[0] = '\0';
    my_stock_nbr(nbr, src);
    src_result = write_text_into_char("HIGH SCORE: ", len);
    my_strcat(src_result, src);
    sfText_setString(text, src_result);
    free(src);
    free(src_result);
}

stats_t main_stats(void)
{
    stats_t stat;

    stat.life = sfText_create();
    stat.score = sfText_create();
    stat.high_score = sfText_create();
    stat.nbr_life = 3;
    stat.nbr_kill = 0;
    stat.nbr_score_max = fs_get_number_from_first_line("./includes/data");
    set_newstring_from_int(stat.score, stat.nbr_score_max);
    set_newstring_from_int(stat.life, stat.nbr_life);
    change_high_score_value_init(stat.high_score, stat.nbr_score_max);
    return stat;
}

static void set_icon(game_t game)
{
    sfRenderWindow_setIcon(game.settings.window, 150, 150,
    sfImage_getPixelsPtr(game.settings.icon));
}

game_t main_bg(void)
{
    game_t game;
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = sfResize | sfFullscreen | sfClose;

    game.settings.window = sfRenderWindow_create(mode, "Hunter", style, NULL);
    sfRenderWindow_setFramerateLimit(game.settings.window, 144);
    game.settings.time_temp = 0;
    sfRenderWindow_setMouseCursorVisible(game.settings.window, sfFalse);
    game.settings.bg_texture = get_texture_from_path("./design/34894.jpg");
    game.settings.bg_sprite = get_bg_from_path(game.settings.bg_texture);
    game.settings.text = sfColor_fromRGB(50, 26, 114);
    game.settings.music_theme =
        sfMusic_createFromFile("design/main_theme.ogg");
    game.settings.icon = sfImage_createFromFile("./design/icon.jpg");
    set_icon(game);
    sfMusic_setVolume(game.settings.music_theme, 75);
    sfMusic_setLoop(game.settings.music_theme, sfTrue);
    game.stat = main_stats();
    game = get_text(game);
    return game;
}
