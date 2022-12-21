/*
** EPITECH PROJECT, 2020
** tower attack
** File description:
** tower attack
*/

#include "../include/game.h"

t_rpg tower_redef(t_rpg game)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 1; j < tow_nb; j++) {
            if (game.towers[i][j].life <= 0) {
                game.towers[i][j].bool = sfFalse;
                game.towers[i][j].pos = (sfVector2f){2000, 2000};
                game.towers[i][j].life = 10 * (game.towers[i][j].pric / 5);
                sfSprite_setPosition(game.towers[i][j].sprite,
                    game.towers[i][j].pos);
            }
        }
    }
    return (game);
}

t_rpg life_tower(t_rpg game)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 1; j < tow_nb; j++) {
            if (sfTime_asSeconds(
                sfClock_getElapsedTime(game.towers[i][j].clock))
                    > 0.5f) {
                sfClock_restart(game.towers[i][j].clock);
                game.towers[i][j].life -= (game.towers[i][j].bool == sfTrue ? 1
                    : 0);
            }
        }
    }
    return (game);
}

t_rpg damage(t_rpg game, t_damage dam, tex_font f_t)
{
    int i = dam.i, j = dam.j, c = dam.c, e = dam.e, a = dam.a, b = dam.b;

    if (game.enemy[i][j].pos.x >= 750 && (game.enemy[i][j].pos.x) <= 800 &&
        game.enemy[i][j].pos.y >= 700 && (game.enemy[i][j].pos.y) <= 800)
        return (game);
    if (game.enemy[i][j].pos.x > (- dam.width + c - 60) &&
        (game.enemy[i][j].pos.x) < (dam.width + 60 + c) &&
        game.enemy[i][j].pos.y > ( - dam.height + e - 60) &&
        (game.enemy[i][j].pos.y) < (e + 60 + dam.height)) {
            game.enemy[i][j].life -= game.towers[a][b].power;
            if (game.enemy[i][j].life >= 0) {
                game = display_bar(game,
                    (t_numb){game.enemy[i][j].life, 10, sfMagenta},
                    (sfVector2f){game.enemy[i][j].pos.x + 30,
                    game.enemy[i][j].pos.y}, f_t);
            }
    }
    return (game);
}

t_rpg tower_attack(t_rpg game, int a, int b, tex_font f_t)
{
    int c = game.towers[a][b].pos.x;
    int e = game.towers[a][b].pos.y;
    sfFloatRect rect = sfSprite_getGlobalBounds(game.towers[a][b].sprite);

    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++)
            game = damage(game,
            (t_damage){i, j, a, b, c, e, rect.width, rect.height}, f_t);
    }
    return (game);
}

t_rpg towers_attack(t_rpg game, tex_font f_t)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 1; j < tow_nb; j++) {
            if (game.towers[i][j].bool)
                game = tower_attack(game, i, j, f_t);
        }
    }
    return (game);
}