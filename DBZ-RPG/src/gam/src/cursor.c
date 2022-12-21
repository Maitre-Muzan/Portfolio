/*
** EPITECH PROJECT, 2020
** cursor
** File description:
** cursor
*/

#include "../include/game.h"

t_rpg cursor(t_rpg game)
{
    game.mouse = sfMouse_getPositionRenderWindow(game.win);
    game.cursor.pos.x = game.mouse.x;
    game.cursor.pos.y = game.mouse.y;
    sfSprite_setPosition(game.cursor.sprite, game.cursor.pos);
    return (game);
}