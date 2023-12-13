/*
** EPITECH PROJECT, 2023
** destroy_page*
** File description:
** destroy
*/

#include "../includes/my.h"

void destroy_bird(game_t *game)
{
    sfTexture_destroy(game->entity.bird.bird_texture);
    sfSprite_destroy(game->entity.bird.img_sprite[0]);
    sfSprite_destroy(game->entity.bird.img_sprite[1]);
    sfSprite_destroy(game->entity.bird.img_sprite[2]);
    sfClock_destroy(game->entity.bird.anim_clock);
    sfClock_destroy(game->entity.bird.clock);
}

static void destroy_gameover(game_t *game)
{
    sfTexture_destroy(game->menu.gameover.gameover_texture);
    sfMusic_destroy(game->menu.gameover.go_music);
    sfMusic_destroy(game->menu.gameover.out_music);
    sfSprite_destroy(game->menu.gameover.sprite);
}

void destroy_stats(game_t *game)
{
    sfText_destroy(game->stat.life);
    sfText_destroy(game->stat.score);
    sfText_destroy(game->stat.high_score);
}

void destroy_extra(game_t *game)
{
    sfTexture_destroy(game->entity.cross.cross_mouse_texture);
    sfTexture_destroy(game->entity.cross.crosshair_texture);
    sfSprite_destroy(game->entity.cross.img_cross_mouse);
    sfSprite_destroy(game->entity.cross.img_crosshair);
    sfTexture_destroy(game->entity.gun.bullet_texture);
    sfSprite_destroy(game->entity.gun.bullet_img);
    sfMusic_destroy(game->settings.music_theme);
    sfMusic_destroy(game->entity.gun.shoot);
}

static void destroy_mainpage(game_t *game)
{
    sfTexture_destroy(game->menu.main_page.bg_texture);
    sfTexture_destroy(game->menu.main_page.main_texture);
    sfSprite_destroy(game->menu.main_page.img_main);
    sfSprite_destroy(game->menu.main_page.img_bg);
}

static void destroy_echap(game_t *game)
{
    sfTexture_destroy(game->menu.echap.echap_texture);
    sfSprite_destroy(game->menu.echap.img_echap);
}

static void destroy_game_background(game_t *game)
{
    sfTexture_destroy(game->settings.bg_texture);
    sfSprite_destroy(game->settings.bg_sprite);
}

void destroy_menu(game_t *game)
{
    destroy_echap(game);
    destroy_game_background(game);
    destroy_mainpage(game);
    destroy_gameover(game);
}
