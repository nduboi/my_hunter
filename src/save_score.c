/*
** EPITECH PROJECT, 2023
** savescore file
** File description:
** save_score
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

void save_score_file(game_t *game)
{
    int fd;
    char *src;
    int len;

    if (game->stat.nbr_score_max <= game->stat.nbr_kill) {
        game->stat.nbr_score_max = game->stat.nbr_kill;
        fd = open("./includes/data", O_RDWR);
        len = my_stock_len(game->stat.nbr_kill);
        src = malloc(sizeof(char) * (len + 3));
        my_stock_nbr(game->stat.nbr_kill, src);
        my_strcat(src, "\n");
        write(fd, src, my_strlen(src));
        free(src);
        close(fd);
    }
}
