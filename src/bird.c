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

static bird_t fill_bird(bird_t bird)
{
    bird.rect.height = 32;
    bird.rect.width = 32;
    bird.rect.left = 0;
    bird.rect.top = 0;
    bird.scale.x = 4;
    bird.scale.y = 4;
    bird.origin.x = -150;
    bird.origin.y = rand() % 700;
    return bird;
}

bird_t main_bird(void)
{
    bird_t bird;

    bird = fill_bird(bird);
    bird.bird_texture = get_texture_from_path
        ("./design/32x32-bat-sprite.png");
    bird.img_sprite = get_sprite_from_path(bird.bird_texture, bird);
    bird.dead = sfMusic_createFromFile("./design/dead_bird_2.ogg");
    bird.clock = sfClock_create();
    bird.anim_clock = sfClock_create();
    return bird;
}
