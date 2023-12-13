/*
** EPITECH PROJECT, 2023
** checkclock
** File description:
** check_sound
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include "../includes/my.h"
#include "../includes/entity.h"

static bird_t check_outside_screen(bird_t bird, int *i, game_t *game)
{
    if ((bird.origin.x >= 2000 || bird.origin.y >= 1020) ||
        game->entity.gun.bullet == 0 ){
        game->entity.gun.bullet = 3;
        bird.origin.x = -150;
        bird.origin.y = rand() % 700;
        *i = 0;
        game->stat.nbr_life = game->stat.nbr_life - 1;
        if (game->stat.nbr_life == 0) {
            sfMusic_stop(game->settings.music_theme);
            start_music(game->menu.gameover.go_music);
        } else {
            start_music(game->menu.gameover.out_music);
        }
        change_life_value(*game);
    }
    return bird;
}

static bird_t move_bird(bird_t *bird, double coef, game_t *game, int *i)
{
    double coef_frame = (game->settings.framerate) / 144;

    if (coef_frame < 0.0)
        coef_frame = coef_frame * -1;
    bird->origin.x += (1 * coef) / coef_frame;
    bird->origin.y += (0.1 * (coef * 1.15));
    *bird = check_outside_screen(*bird, i, game);
    sfClock_restart(game->entity.bird.clock);
    return *bird;
}

static void change_annim(int *i, game_t *game)
{
    if (*i >= 0 && *i < 2){
        sfClock_restart(game->entity.bird.anim_clock);
        *i = *i + 1;
    }else {
        sfClock_restart(game->entity.bird.anim_clock);
        *i = 0;
    }
}

static void modify_max_score(game_t *game)
{
    if (game->stat.nbr_score_max < game->stat.nbr_kill) {
        game->stat.nbr_score_max = game->stat.nbr_kill;
        sfText_setColor(game->stat.high_score, sfGreen);
        change_high_score_value(*game);
        save_score_file(game);
    }
}

void get_fps(game_t *game, int time_2)
{
    game->settings.framerate = 1 / ((time_2 - game->settings.time_temp)
        * 0.001);
    game->settings.time_temp = time_2;
}

void clock_bird_disp(int *i, game_t *game, bird_t bird)
{
    double coef;
    int time = sfTime_asMicroseconds(sfClock_getElapsedTime(
        game->entity.bird.clock));
    int time_2 = sfTime_asMilliseconds(sfClock_getElapsedTime(
        game->entity.bird.anim_clock));

    bird.origin = sfSprite_getPosition(bird.img_sprite[*i]);
    coef = 1 + ((double)(game->stat.nbr_kill * 0.1));
    get_fps(game, time_2);
    if (time >= (6000))
        bird = move_bird(&bird, coef, game, i);
    if (time_2 >= 114)
        change_annim(i, game);
    modify_max_score(game);
    sfSprite_setPosition(bird.img_sprite[*i], bird.origin);
}
