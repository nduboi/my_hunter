/*
** EPITECH PROJECT, 2023
** includes
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "entity.h"
#include <time.h>
#include <SFML/Audio.h>

#ifndef MY_H_
    #define MY_H_

sfSprite **get_sprite_from_path(sfTexture *img_texture, bird_t bird);
sfSprite *get_bg_from_path(sfTexture *texture);
sfTexture *get_texture_from_path(char *path);
game_t main_bg(void);
game_over_t main_gameover(void);
echap_t main_echap(void);
main_page_t main_page(void);
bird_t main_bird(void);
cross_t main_cross(void);
stats_t main_stats(void);
gun_t main_gun(void);
char *write_text_into_char(char *src, int len_nbr);
void save_score_file(game_t *game);
int my_strcmp(const char *first, const char *second);
int my_putstr(char const *str);
void touch_espace_press(game_t *game);
void display_echap_mode(game_t *bg);
void display_main_menu(game_t *game);
void clock_bird_disp(int *i, game_t *game, bird_t bird);
void analyse_events(game_t *game, sfEvent event,
    sfSprite* img_sprite);
int my_stock_len(int nb);
char *my_stock_nbr(int nb, char *src);
void change_life_value(game_t game);
void change_score_value(game_t game);
void change_high_score_value(game_t game);
void start_music(sfMusic *music);
void close_windows(game_t *game);
int fs_get_number_from_first_line(char const *filepath);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void destroy_bird(game_t *game);
void destroy_stats(game_t *game);
void destroy_extra(game_t *game);
void destroy_menu(game_t *game);

#endif /* !MY_H_ */
