/*
** EPITECH PROJECT, 2020
** tower
** File description:
** tower
*/

#include "../include/game.h"

t_rpg put_tower(t_rpg game, int i)
{
    for (int j = 1; j < tow_nb; j++) {
        if (!game.towers[i][j].bool &&
        my_getnbr(prices[game.towers[i][i].price_id]) <= game.money) {
            game.towers[i][j].bool = sfTrue;
            game.money -= my_getnbr(prices[game.towers[i][i].price_id]);
            game.towers[i][j].pos.x = game.marker[game.mark_id].pos.x;
            game.towers[i][j].pos.y = game.marker[game.mark_id].pos.y - 30;
            return (game);
        }
    }
    return (game);
}

int is_tower(t_rpg game)
{
    float a = (float)game.mouse.x;
    float b = (float)game.mouse.y;
    sfFloatRect rect;

    for (int i = 0; i < tow_type; i++) {
        rect = sfSprite_getGlobalBounds(game.towers[i][0].sprite);
        if (a > game.towers[i][0].pos.x && a <
            (game.towers[i][0].pos.x + rect.width) &&
            b > game.towers[i][0].pos.y  && b <
            (game.towers[i][0].pos.y + rect.height))
            return (i);
    }
    return (-1);
}

void print_tower_price(t_rpg game, t_tower tower, tex_font f_t)
{
    sfText *price_text = sfText_create();

    sfText_setString(price_text, prices[tower.price_id]);
    sfText_setFont(price_text, f_t.font[0]);
    sfText_setCharacterSize(price_text, 50);
    sfText_setPosition(price_text,
            (sfVector2f){tower.pos.x + 80, tower.pos.y + 80});
    sfRenderWindow_drawText(game.win, price_text, NULL);
    sfText_destroy(price_text);
}

void destroy_tower(t_rpg game)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 0; j < tow_nb; j++) {
            sfSprite_destroy(game.towers[i][j].sprite);
            sfClock_destroy(game.towers[i][j].clock);
        }
        free(game.towers[i]);
    }
    free(game.towers);
}

t_rpg init_tower(t_rpg game, tex_font f_t)
{
    game.towers = malloc(sizeof(t_tower *) * tow_type);
    for (int i = 0, a = 4, pric = 25; i < tow_type; a++, i++, pric += 25) {
        game.towers[i] = malloc(sizeof(t_tower) * tow_nb);
        for (int j = 0; j < tow_nb; j++) {
            game.towers[i][j].sprite = sfSprite_create();
            sfSprite_setTexture(game.towers[i][j].sprite,
                f_t.texture[a], sfTrue);
            game.towers[i][j].bool = sfFalse;
            game.towers[i][j].life = 10 * (pric / 5);
            game.towers[i][j].pric = pric;
            game.towers[i][j].power = pric / 2;
            game.towers[i][j].price_id = i;
            game.towers[i][j].clock = sfClock_create();
            if (j > 0)
                game.towers[i][j].pos = (sfVector2f){2000, 2000};
        }
    }
    return (game);
}
