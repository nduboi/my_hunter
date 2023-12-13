/*
** EPITECH PROJECT, 2023
** gun fct main
** File description:
** gun
*/

#include "../includes/my.h"

gun_t main_gun(void)
{
    gun_t gun;

    gun.bullet = 3;
    gun.bullet_texture = get_texture_from_path("./design/clipart1071486.png");
    gun.bullet_img = get_bg_from_path(gun.bullet_texture);
    gun.shoot = sfMusic_createFromFile("./design/shoot.ogg");
    return gun;
}
