/*
** EPITECH PROJECT, 2023
** crosshair
** File description:
** crosshair
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

cross_t main_cross(void)
{
    cross_t cross;
    sfVector2f orign;

    orign.x = 111;
    orign.y = 75.5;
    cross.crosshair_texture = get_texture_from_path("./design/crosshaire.png");
    cross.img_crosshair = get_bg_from_path(cross.crosshair_texture);
    cross.cross_mouse_texture = get_texture_from_path
        ("./design/mouse_cross.png");
    cross.img_cross_mouse = get_bg_from_path(cross.cross_mouse_texture);
    sfSprite_setOrigin(cross.img_crosshair, orign);
    return cross;
}
