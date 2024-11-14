/*
** EPITECH PROJECT, 2022
** WE_02 count_island
** File description:
** This will look at a txt and find the
** number of island of xs there are
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void my_mark_as_seen(char ** world, unsigned int y,
unsigned int x, unsigned int count);

void my_mark_as_seen_col(char ** world, unsigned int y,
unsigned int x, unsigned int count)
{
    if (world[y + 1] == NULL)
        return;
    if (world[y + 1][x] == 'X')
        my_mark_as_seen(world, y + 1, x, count);
    if (y == 0)
        return;
    if (world[y - 1][x] == 'X')
        my_mark_as_seen(world, y - 1, x, count);
}

void my_mark_as_seen_line(char ** world, unsigned int y,
unsigned int x, unsigned int count)
{
    if (world[y][x + 1] == '\0')
        return;
    if (world[y][x + 1] == 'X')
        my_mark_as_seen(world, y, x + 1, count);
    if (x < 1)
        return;
    if (world[y][x - 1] == 'X')
        my_mark_as_seen(world, y, x - 1, count);
}

void my_mark_as_seen(char ** world, unsigned int y,
unsigned int x, unsigned int count)
{
    if (test_is_num(world[y][x]) == 1 )
        return;
    if (world[y][x] == '.')
        return;
    world[y][x] = count + '0';
    my_mark_as_seen_col(world, y, x, count);
    my_mark_as_seen_line(world, y, x, count);
}

int count_island2(char ** world, int count, int y, int x)
{
    if (world[y][x] == 'X'){
        my_mark_as_seen(world, y, x, count);
        count++;
    }
    return count;
}

int count_island(char ** world)
{
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int count = 0;

    while (world[y] != NULL  ) {
        while (world[y][x] != '\0') {
            count = count_island2(world, count, y, x);
            x++;
        }
        x = 0;
        y++;
    }
    return count;
}
