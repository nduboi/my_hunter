/*
** EPITECH PROJECT, 2023
** step6
** File description:
** step6
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/my.h"

int my_fget_nbr(char *buff, int i)
{
    double coef = 0.1;
    int nbr = 0;

    for (int k = i - 1; k >= 0; k--) {
        coef = coef * 10;
        if (buff[k] >= '0' && buff[k] <= '9') {
            nbr += ((buff[k] - '0') * (int) coef);
        }else {
            return 0;
        }
    }
    return nbr;
}

int fs_get_number_from_first_line(char const *filepath)
{
    int fd;
    char buff[2048] = "";
    int i = 0;
    int nbr = 0;

    fd = open(filepath, O_RDONLY);
    read(fd, buff, 2048);
    if (fd == -1) {
        return 84;
    }
    while (buff[i] != '\n' || i == 2047) {
        i++;
    }
    nbr = my_fget_nbr(buff, i);
    close(fd);
    return nbr;
}
