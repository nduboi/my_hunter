/*
** EPITECH PROJECT, 2023
** My_hunter
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "../includes/my.h"
#include "../includes/entity.h"
#include <stdio.h>
#include <SFML/Audio.h>

cross_t track_mouse(game_t game)
{
    mouse_t mouse;
    sfVector2i posi_mouse;

    posi_mouse = sfMouse_getPositionRenderWindow(game.settings.window);
    mouse.pos.x = posi_mouse.x;
    mouse.pos.y = posi_mouse.y;
    sfSprite_setPosition(game.entity.cross.img_crosshair, mouse.pos);
    sfSprite_setPosition(game.entity.cross.img_cross_mouse, mouse.pos);
    return game.entity.cross;
}

static void game_over_diplay(game_t *game)
{
    sfClock_restart(game->entity.bird.clock);
    sfText_setColor(game->stat.life, game->menu.gameover.text);
    sfText_setColor(game->stat.score, game->menu.gameover.text);
    sfRenderWindow_drawText(game->settings.window, game->stat.life, NULL);
    sfRenderWindow_drawSprite(game->settings.window,
        game->menu.gameover.sprite, NULL);
    save_score_file(game);
    sfRenderWindow_drawText(game->settings.window, game->stat.score, NULL);
    sfRenderWindow_drawText(game->settings.window, game->stat.high_score,
        NULL);
}

static void spawn_nbr_bullet(game_t *bg)
{
    sfVector2f pos_gun;

    pos_gun.x = 860;
    pos_gun.y = 0;
    sfSprite_setPosition(bg->entity.gun.bullet_img, pos_gun);
    for (int i = 0; i < bg->entity.gun.bullet; i++) {
        sfRenderWindow_drawSprite(bg->settings.window,
            bg->entity.gun.bullet_img, NULL);
        pos_gun = sfSprite_getPosition(bg->entity.gun.bullet_img);
        pos_gun.x += 70;
        sfSprite_setPosition(bg->entity.gun.bullet_img, pos_gun);
    }
}

static void display_game(game_t *bg, int i)
{
    sfText_setColor(bg->stat.life, bg->settings.text);
    sfText_setColor(bg->stat.score, bg->settings.text);
    sfRenderWindow_drawText(bg->settings.window, bg->stat.life, NULL);
    sfRenderWindow_drawText(bg->settings.window, bg
        ->stat.score, NULL);
    sfRenderWindow_drawText(bg->settings.window, bg
        ->stat.high_score, NULL);
    sfRenderWindow_drawSprite(bg->settings.window,
        bg->entity.bird.img_sprite[i],
        NULL);
    spawn_nbr_bullet(bg);
    sfRenderWindow_drawSprite(bg->settings.window,
        bg->entity.cross.img_crosshair, NULL);
}

void display_sprite(game_t *bg, int i)
{
    sfRenderWindow_drawSprite(bg->settings.window, bg->settings.bg_sprite,
        NULL);
    if (bg->stat.nbr_life != 0){
        display_game(bg, i);
    } else
        game_over_diplay(bg);
    if (bg->menu.main_page.menu_mode == 1)
        display_main_menu(bg);
    if (bg->menu.echap.echap_mode == 1) {
        sfClock_restart(bg->entity.bird.clock);
        display_echap_mode(bg);
    }
}

void open_windows(game_t bg)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_isOpen(bg.settings.window)) {
        while (sfRenderWindow_pollEvent(bg.settings.window, &event)) {
            analyse_events(&bg, event, bg.entity.bird.img_sprite[i]);
        }
        sfRenderWindow_clear(bg.settings.window, sfBlack);
        bg.entity.cross = track_mouse(bg);
        display_sprite(&bg, i);
        clock_bird_disp(&i, &bg, bg.entity.bird);
        sfRenderWindow_display(bg.settings.window);
    }
    sfRenderWindow_destroy(bg.settings.window);
}

void destroy_windows(game_t *bg)
{
    destroy_extra(bg);
    destroy_stats(bg);
    destroy_menu(bg);
    destroy_bird(bg);
}

static int main_game(void)
{
    game_t bg = main_bg();

    bg.menu.main_page = main_page();
    bg.menu.gameover = main_gameover();
    bg.menu.echap = main_echap();
    bg.entity.bird = main_bird();
    bg.entity.cross = main_cross();
    bg.entity.gun = main_gun();
    if (!bg.settings.window || !bg.entity.bird.img_sprite ||
        !bg.settings.bg_sprite ||
        !bg.entity.cross.img_crosshair || !bg.menu.echap.img_echap)
        return EXIT_FAILURE;
    open_windows(bg);
    destroy_windows(&bg);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0) {
            my_putstr("Le jeu est un jeu developper par Noa ROUSSIERE");
            my_putstr("a Epitech en tek 1 promo 2028\n");
        }
    } else {
        main_game();
    }
}
