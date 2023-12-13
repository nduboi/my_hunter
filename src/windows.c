/*
** EPITECH PROJECT, 2023
** windows fct
** File description:
** windows
*/

#include "../includes/my.h"

void close_windows(game_t *game)
{
    sfRenderWindow_close(game->settings.window);
}
