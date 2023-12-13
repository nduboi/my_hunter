/*
** EPITECH PROJECT, 2023
** display_echap
** File description:
** echap_mode
*/

#include "../includes/my.h"

void display_echap_mode(game_t *bg)
{
    sfRenderWindow_clear(bg->settings.window, sfBlack);
    sfRenderWindow_drawSprite(bg->settings.window, bg->settings.bg_sprite,
        NULL);
    sfRenderWindow_drawText(bg->settings.window, bg->stat.life, NULL);
    sfRenderWindow_drawText(bg->settings.window, bg->stat.score, NULL);
    sfRenderWindow_drawText(bg->settings.window, bg->stat.high_score, NULL);
    sfRenderWindow_drawSprite(bg->settings.window, bg->menu.echap.img_echap,
        NULL);
    sfRenderWindow_drawSprite(bg->settings.window,
    bg->entity.cross.img_cross_mouse, NULL);
}

void display_main_menu(game_t *game)
{
    sfClock_restart(game->entity.bird.clock);
    sfRenderWindow_clear(game->settings.window, sfBlack);
    sfRenderWindow_drawSprite(game->settings.window,
        game->menu.main_page.img_bg, NULL);
    sfRenderWindow_drawSprite(game->settings.window,
    game->menu.main_page.img_main, NULL);
    sfRenderWindow_drawSprite(game->settings.window,
    game->entity.cross.img_cross_mouse, NULL);
}

void touch_espace_press(game_t *game)
{
    if (game->menu.echap.echap_mode == 0 &&
        game->menu.main_page.menu_mode != 1) {
        sfMusic_pause(game->settings.music_theme);
        game->menu.echap.echap_mode = 1;
    } else if (game->menu.echap.echap_mode == 1 &&
        game->menu.main_page.menu_mode != 1 && game->stat.nbr_life != 0) {
        sfMusic_play(game->settings.music_theme);
        game->menu.echap.echap_mode = 0;
    }
}
