/*
** EPITECH PROJECT, 2020
** enemy
** File description:
** enemy
*/

#include "../include/game.h"

t_rpg effect_enemy(t_rpg game, tex_font f_t)
{
    float a = (float)game.mouse.x;
    float b = (float)game.mouse.y;
    sfFloatRect rect;

    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            rect = sfSprite_getGlobalBounds(game.enemy[i][j].sprite);
            if (a > game.enemy[i][j].pos.x && a <
                (game.enemy[i][j].pos.x + rect.width + 20) &&
                b > game.enemy[i][j].pos.y && b <
                (game.enemy[i][j].pos.y + rect.height + 20) &&
                game.enemy[i][j].alive) {
                game = display_bar(game,
                    (t_numb){game.enemy[i][j].life, 10, sfMagenta},
                    (sfVector2f){game.enemy[i][j].pos.x + 30,
                    game.enemy[i][j].pos.y}, f_t);
            }
        }
    }
    return (game);
}

void destroy_enemy(t_rpg game)
{
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            sfSprite_destroy(game.enemy[i][j].sprite);
            sfClock_destroy(game.enemy[i][j].clock);
        }
        free(game.enemy[i]);
    }
    free(game.enemy);
}

t_enemy set_enemy(t_enemy enemy, int val)
{
    enemy.alive = sfTrue;
    enemy.life = 10 * val;
    enemy.walk_front[0] = 0;
    enemy.walk_right[0] = 10;
    enemy.walk_left[0] = 17;
    enemy.walk_front[1] = 9;
    enemy.walk_right[1] = 16;
    enemy.walk_left[1] = 23;
    enemy.inc = 80;
    enemy.pos = (sfVector2f){2000, 2000};
    sfSprite_setPosition(enemy.sprite, enemy.pos);
    enemy.clock = sfClock_create();
    enemy.rect = (sfIntRect){0, 0, 79, 81};
    enemy.section = 0;
    sfSprite_setTextureRect(enemy.sprite, enemy.rect);
    return (enemy);
}

t_rpg init_enemy(t_rpg game, tex_font f_t)
{
    sfColor color = sfColor_fromRGB(0, 185, 198);

    game.enemy = malloc(sizeof(t_enemy *) * type_enemy);
    for (int i = 0, pric = 25; i < type_enemy; i++, pric += 10) {
        game.enemy[i] = malloc(sizeof(t_enemy) * nb_enemy);
        for (int j = 0; j < nb_enemy; j++) {
            game.enemy[i][j].sprite = sfSprite_create();
            sfSprite_setTexture(game.enemy[i][j].sprite,
                                f_t.texture[9], sfTrue);
            game.enemy[i][j] = set_enemy(game.enemy[i][j], pric);
            if (i == 1)
                sfSprite_setColor(game.enemy[i][j].sprite, color);
        }
    }
    return (game);
}