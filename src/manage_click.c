/*
** EPITECH PROJECT, 2023
** manage click
** File description:
** manage_click
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/entity.h"
#include "../includes/my.h"
#include <stdio.h>
#include <SFML/Audio.h>

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void start_music(sfMusic *music)
{
    sfVector3f pos;

    pos.x = 0;
    pos.z = 0;
    pos.y = 0;
    sfMusic_stop(music);
    sfMusic_setPosition(music, pos);
    sfMusic_play(music);
}

static void respawn_bird(game_t *game, sfSprite *img_sprite)
{
    sfVector2f pos;

    pos.x = -45;
    pos.y = rand() % 700;
    pos.y += 100;
    game->entity.gun.bullet = 3;
    game->stat.nbr_kill = game->stat.nbr_kill + 1;
    change_score_value(*game);
    sfSprite_setPosition(img_sprite, pos);
}

static void restart_game(game_t *game, sfSprite *img_sprite)
{
    sfVector3f pos;

    game->menu.echap.echap_mode = 0;
    game->stat.nbr_kill = -1;
    game->stat.nbr_life = 3;
    pos.x = 0;
    pos.z = 0;
    pos.y = 0;
    sfMusic_setPosition(game->settings.music_theme, pos);
    sfMusic_play(game->settings.music_theme);
    sfText_setColor(game->stat.high_score, sfWhite);
    start_music(game->settings.music_theme);
    change_score_value(*game);
    change_life_value(*game);
    respawn_bird(game, img_sprite);
}

static void catch_menu_sec(game_t *game, sfSprite *img_sprite,
    sfMouseButtonEvent event)
{
    if ((event.x >= 785 && event.x <= 1120) &&
        (event.y >= 495 && event.y <= 565)){
        game->menu.main_page.menu_mode = 0;
        restart_game(game, img_sprite);
    }
    if ((event.x >= 870 && event.x <= 1035) &&
        (event.y >= 695 && event.y <= 735)){
        close_windows(game);
    }
}

static void catch_menu(game_t *game, sfSprite *img_sprite,
    sfMouseButtonEvent event)
{
    if (game->menu.echap.echap_mode == 1) {
        if ((event.x >= 810 && event.x <= 1075) &&
            (event.y >= 460 && event.y <= 505)){
            game->menu.echap.echap_mode = 0;
            sfMusic_play(game->settings.music_theme);
        }
        if ((event.x >= 795 && event.x <= 1090) &&
            (event.y >= 590 && event.y <= 640)){
            restart_game(game, img_sprite);
        }
        if ((event.x >= 864 && event.x <= 1024) &&
            (event.y >= 730 && event.y <= 772)){
            close_windows(game);
        }
    } else {
        catch_menu_sec(game, img_sprite, event);
    }
}

void manage_mouse_click(sfMouseButtonEvent event, sfSprite *img_sprite,
    game_t *game)
{
    sfVector2f pos;

    if (((event.button == sfMouseLeft ) && game->menu.echap.echap_mode != 1 &&
        game->stat.nbr_life != 0 && game->menu.main_page.menu_mode != 1 &&
        game->entity.gun.bullet > 0 )) {
        pos = sfSprite_getPosition(img_sprite);
        game->entity.gun.bullet = game->entity.gun.bullet - 1;
        start_music(game->entity.gun.shoot);
        if (((event.x >= pos.x && event.x <= pos.x + 100) &&
            (event.y >= pos.y && event.y <= pos.y + 100))){
            start_music(game->entity.bird.dead);
            respawn_bird(game, img_sprite);
        }
    }
    if ((event.button == sfMouseLeft) && (game->menu.echap.echap_mode != 0 ||
        game->menu.main_page.menu_mode != 0)) {
        pos = sfSprite_getPosition(game->menu.echap.img_echap);
        catch_menu(game, img_sprite, event);
    }
    return;
}

static void restart_game_aftergameover(game_t *game)
{
    game->stat.nbr_life = 3;
    game->stat.nbr_kill = 0;
    start_music(game->settings.music_theme);
    change_life_value(*game);
    change_score_value(*game);
    change_high_score_value(*game);
    sfText_setColor(game->stat.life, game->settings.text);
    sfText_setColor(game->stat.high_score, sfWhite);
    sfText_setColor(game->stat.score, game->settings.text);
}

game_t manage_key_click(sfKeyEvent event, game_t *game)
{
    if (game->stat.nbr_life == 0) {
        if (event.code == sfKeyR) {
            restart_game_aftergameover(game);
        }
    }
    if (event.code == sfKeyEscape) {
        touch_espace_press(game);
    }
    return *game;
}

void analyse_events(game_t *game, sfEvent event,
    sfSprite* img_sprite)
{
    if (event.type == sfEvtClosed){
        close_window(game->settings.window);
    }
    if (event.type == sfEvtMouseButtonPressed){
        manage_mouse_click(event.mouseButton, img_sprite, game);
    }
    if (event.type == sfEvtKeyPressed){
        *game = manage_key_click(event.key, game);
    }
}
