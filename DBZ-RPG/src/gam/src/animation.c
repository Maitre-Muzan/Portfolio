/*
** EPITECH PROJECT, 2020
** animation
** File description:
** animation
*/

#include "../include/game.h"

spr_tex animate(spr_tex spr, int nb, int inc, float speed)
{
    sfTime time = sfClock_getElapsedTime(spr.clock);

    if (sfTime_asSeconds(time) > speed) {
        if (spr.rect.left == ((nb - 1) * inc))
            spr.rect.left = 0;
        else
            spr.rect.left += inc;
        sfClock_restart(spr.clock);
        sfSprite_setTextureRect(spr.sprite, spr.rect);
    }
    return (spr);
}