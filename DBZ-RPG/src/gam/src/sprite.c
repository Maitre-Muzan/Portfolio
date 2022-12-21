/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** sprite
*/

#include "../include/game.h"

void destroy_sprite(t_rpg game)
{
    sfSprite_destroy(game.menu_bg.sprite);
    sfSprite_destroy(game.cursor.sprite);
    sfSprite_destroy(game.logo.sprite);
    sfSprite_destroy(game.map.sprite);
    sfSprite_destroy(game.coin.sprite);
}

t_rpg init_sprite(t_rpg game, tex_font f_t)
{
    game.menu_bg.sprite = sfSprite_create();
    sfSprite_setTexture(game.menu_bg.sprite, f_t.texture[0], sfTrue);
    game.cursor.sprite = sfSprite_create();
    sfSprite_setTexture(game.cursor.sprite, f_t.texture[1], sfTrue);
    game.logo.sprite = sfSprite_create();
    sfSprite_setTexture(game.logo.sprite, f_t.texture[2], sfTrue);
    game.logo.pos = (sfVector2f){700, 50};
    sfSprite_setPosition(game.logo.sprite, game.logo.pos);
    game.map.sprite = sfSprite_create();
    sfSprite_setTexture(game.map.sprite, f_t.texture[3], sfTrue);
    game.map.pos = (sfVector2f){260, 60};
    sfSprite_setPosition(game.map.sprite, game.map.pos);
    game = init_coin(game, f_t);
    return (game);
}
