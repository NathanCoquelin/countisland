/*
** EPITECH PROJECT, 2022
** count_island_max
** File description:
** This will compose the new files used in the bonus
*/

#include "my.h"
#include <stdlib.h>

int get_max_horizontal(char ** world)
{
    unsigned int i = 0;

    while (world[0][i] != '\0') {
        i++;
    }
    return i - 1;
}

int get_max_vertical(char **world)
{
    unsigned int i = 0;

    while (world[i] != NULL)
        i++;
    return i - 1;
}
