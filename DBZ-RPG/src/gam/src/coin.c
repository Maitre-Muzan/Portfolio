/*
** EPITECH PROJECT, 2020
** coin
** File description:
** coin
*/

#include "../include/game.h"

t_rpg init_coin(t_rpg game, tex_font f_t)
{
    game.coin.sprite = sfSprite_create();
    sfSprite_setTexture(game.coin.sprite, f_t.texture[8], sfTrue);
    game.coin.pos = (sfVector2f){10, 10};
    sfSprite_setPosition(game.coin.sprite, game.coin.pos);
    game.coin.clock = sfClock_create();
    game.coin.rect = (sfIntRect){0, 0, 60, 60};
    sfSprite_setTextureRect(game.coin.sprite, game.coin.rect);
    return (game);
}