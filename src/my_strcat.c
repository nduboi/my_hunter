/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Write a function that concatenates two strings
*/
#include "../includes/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int i = 0;
    int j = 0;

    for (i = len_dest; src[j] != '\0'; i++) {
        dest[i] = src[j];
        j++;
    }
    dest[i] = '\0';
    return dest;
}
