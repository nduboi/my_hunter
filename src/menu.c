/*
** EPITECH PROJECT, 2023
** load all menu files
** File description:
** menu
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

main_page_t main_page(void)
{
    main_page_t page;

    page.main_texture = get_texture_from_path("./design/main_menu.png");
    page.img_main = get_bg_from_path(page.main_texture);
    page.bg_texture = get_texture_from_path("./design/menumain.jpg");
    page.img_bg = get_bg_from_path(page.bg_texture);
    page.menu_mode = 1;
    return page;
}

game_over_t main_gameover(void)
{
    game_over_t gameover;

    gameover.gameover_texture = get_texture_from_path("./design/gameover.png");
    gameover.sprite = get_bg_from_path(gameover.gameover_texture);
    gameover.go_music = sfMusic_createFromFile("./design/gameover.ogg");
    gameover.out_music = sfMusic_createFromFile("./design/outside.ogg");
    gameover.text = sfRed;
    return gameover;
}

echap_t main_echap(void)
{
    echap_t echap;

    echap.echap_texture = get_texture_from_path("./design/echap.png");
    echap.img_echap = get_bg_from_path(echap.echap_texture);
    echap.echap_mode = 0;
    return echap;
}
