/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include <unistd.h>
#include "../includes/my.h"
#include <stdlib.h>

int my_strcmp(const char *first, const char *second)
{
    if (my_strlen(first) != my_strlen(second))
        return -1;
    for (int i = 0; first[i]; i++) {
        if (first[i] != second[i])
            return first[i] - second[i];
    }
    return 0;
}
