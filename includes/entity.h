/*
** EPITECH PROJECT, 2023
** entity
** File description:
** entity
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>

#ifndef ENTITY_H_
    #define ENTITY_H_

typedef struct bird {
    sfSprite **img_sprite;
    sfTexture *bird_texture;
    sfMusic *dead;
    sfIntRect rect;
    sfVector2f origin;
    sfVector2f scale;
    sfClock *clock;
    sfClock *anim_clock;
} bird_t;

typedef struct mouse {
    sfVector2f pos;
} mouse_t;

typedef struct cross {
    sfSprite *img_crosshair;
    sfTexture *crosshair_texture;
    sfSprite *img_cross_mouse;
    sfTexture *cross_mouse_texture;
} cross_t;

typedef struct gun {
    sfMusic *shoot;
    sfSprite *bullet_img;
    sfTexture *bullet_texture;
    int bullet;
} gun_t;

typedef struct entity {
    gun_t gun;
    cross_t cross;
    bird_t bird;
} entity_t;

typedef struct game_over {
    sfSprite *sprite;
    sfTexture *gameover_texture;
    sfColor text;
    sfMusic *go_music;
    sfMusic *out_music;
} game_over_t;

typedef struct stats {
    sfText *life;
    int nbr_life;
    sfText *score;
    int nbr_kill;
    sfText *high_score;
    int nbr_score_max;
} stats_t;

typedef struct echap {
    int echap_mode;
    sfSprite *img_echap;
    sfTexture *echap_texture;
} echap_t;

typedef struct main_page {
    int menu_mode;
    sfSprite *img_bg;
    sfTexture *bg_texture;
    sfSprite *img_main;
    sfTexture *main_texture;
} main_page_t;

typedef struct menu {
    echap_t echap;
    game_over_t gameover;
    main_page_t main_page;
} menu_t;

typedef struct settings_game {
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
    sfRenderWindow *window;
    sfColor text;
    sfImage *icon;
    sfMusic *music_theme;
    float framerate;
    int time_temp;
}settings_game_t;

typedef struct game {
    settings_game_t settings;
    menu_t menu;
    stats_t stat;
    entity_t entity;
} game_t;

#endif /* !ENTITY_H_ */
