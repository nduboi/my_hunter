/*
** EPITECH PROJECT, 2023
** get_spirte frompath
** File description:
** get_sprite
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

sfTexture *get_texture_from_path(char *path)
{
    sfTexture *img_texture;

    img_texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setSmooth(img_texture, sfTrue);
    return img_texture;
}

sfSprite *get_bg_from_path(sfTexture *texture)
{
    sfSprite *img_sprite;

    sfTexture_setSmooth(texture, sfTrue);
    img_sprite = malloc(sizeof(sfSprite *) * 4);
    img_sprite = sfSprite_create();
    sfSprite_setTexture(img_sprite, texture, sfTrue);
    return img_sprite;
}

sfSprite **get_sprite_from_path(sfTexture *img_texture, bird_t bird)
{
    sfSprite **img_sprite;

    img_sprite = malloc(sizeof(sfSprite *) * 5);
    for (int i = 0; i < 4; i++) {
        img_sprite[i] = malloc(sizeof(sfSprite *));
        img_sprite[i] = sfSprite_create();
        sfSprite_setTexture(img_sprite[i], img_texture, sfTrue);
        sfSprite_setPosition(img_sprite[i], bird.origin);
        sfSprite_setTextureRect(img_sprite[i], bird.rect);
        bird.rect.left += 32;
        sfSprite_setScale(img_sprite[i], bird.scale);
    }
    return img_sprite;
}
