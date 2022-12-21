/*
** EPITECH PROJECT, 2019
** runner
** File description:
** my_runner
*/

#include "../../../include/steph_rpg.h"

void goku_on(t_goku *goku)
{
    sfColor tmp;

    tmp = sfImage_getPixel(goku->black, goku->position.x,
    goku->position.y + 5 + 35);
    if (tmp.r == 255 && tmp.g == 255 && tmp.b == 255)
        goku->position.y += 5;
    goku->time = sfClock_getElapsedTime(goku->clock1);
    goku->rec.top = 0;
    if (sfTime_asSeconds(goku->time) > 0.1f) {
        if (goku->rec.left == 66)
            goku->rec.left = 0;
        else
            goku->rec.left = goku->rec.left + 33;
        if (goku->position.y < 2250)
            goku->position.y += 5;
        sfClock_restart(goku->clock1);
    }
}

void goku_back(t_goku *goku)
{
    sfColor tmp;

    tmp = sfImage_getPixel(goku->black, goku->position.x,
    goku->position.y - 5);
    if (tmp.r == 255 && tmp.g == 255 && tmp.b == 255)
        goku->position.y -= 5;
    goku->time = sfClock_getElapsedTime(goku->clock2);
    goku->rec.top = 35 * 3;
    if (sfTime_asSeconds(goku->time) > 0.1f) {
        if (goku->rec.left == 66)
            goku->rec.left = 0;
        else
            goku->rec.left = goku->rec.left + 33;
        sfClock_restart(goku->clock2);
    }
}

void goku_left(t_goku *goku)
{
    sfColor tmp;

    tmp = sfImage_getPixel(goku->black, goku->position.x - 5,
    goku->position.y);
    if (tmp.r == 255 && tmp.g == 255 && tmp.b == 255)
        goku->position.x -= 5;
    goku->time = sfClock_getElapsedTime(goku->clock3);
    goku->rec.top = 35;
    if (sfTime_asSeconds(goku->time) > 0.1f) {
        if (goku->rec.left == 66)
            goku->rec.left = 0;
        else
            goku->rec.left = goku->rec.left + 33;
        sfClock_restart(goku->clock3);
    }
}

void goku_right(t_goku *goku)
{
    sfColor tmp;

    tmp = sfImage_getPixel(goku->black, goku->position.x + 5 + 33,
    goku->position.y);
    if (tmp.r == 255 && tmp.g == 255 && tmp.b == 255)
        goku->position.x += 5;
    goku->time = sfClock_getElapsedTime(goku->clock4);
    goku->rec.top = 35 * 2;
    if (sfTime_asSeconds(goku->time) > 0.1f) {
        if (goku->rec.left == 66)
            goku->rec.left = 0;
        else
            goku->rec.left = goku->rec.left + 33;
        sfClock_restart(goku->clock4);
    }
}
