/*
** EPITECH PROJECT, 2020
** clock
** File description:
** clock
*/

#include "../include/game.h"

void destroy_clock(t_rpg game)
{
    sfClock_destroy(game.coin.clock);
}