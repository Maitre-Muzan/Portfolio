/*
** EPITECH PROJECT, 2020
** put enemy
** File description:
** put enemy
*/

#include "../include/game.h"

static int no_more(t_rpg game)
{
    int count = 0;

    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            if (OUT(game.enemy[i][j].pos.x,
            game.enemy[i][j].pos.y)) {
                count++;
            }
        }
    }
    return (count);
}

t_ij find_enemy(t_rpg game, t_ij ij)
{

    for (ij.j = 0; (IN(game.enemy[ij.i][ij.j].pos.x,
    game.enemy[ij.i][ij.j].pos.y) ||
    DEAD(game.enemy[ij.i][ij.j].pos.x, game.enemy[ij.i][ij.j].pos.y)) &&
    ij.j < nb_enemy; ij.j++) {
        srand(rand_seed());
        if (ij.j == (nb_enemy - 2) && (IN(game.enemy[ij.i][ij.j + 1].pos.x,
            game.enemy[ij.i][ij.j + 1].pos.y) ||
            DEAD(game.enemy[ij.i][ij.j].pos.x,
            game.enemy[ij.i][ij.j].pos.y))) {
            ij.i = (ij.i == 1 ? 0 : 1);
            ij.j = 0;
        }
    }
    return (ij);
}

t_rpg put_enemies(t_rpg game)
{
    t_ij ij = {rand() % (1 + 1 - 0) + 0, 0};

    if (sfTime_asSeconds(sfClock_getElapsedTime(game.clock)) > 1.0f) {
        if (!no_more(game))
            return (game);
        if ((ij.i != 0 && ij.i != 1) || (ij.j < 0 || ij.j >= nb_enemy)
        || IN(game.enemy[ij.i][ij.j].pos.x, game.enemy[ij.i][ij.j].pos.y) ||
        DEAD(game.enemy[ij.i][ij.j].pos.x, game.enemy[ij.i][ij.j].pos.y)) {
            ij.i = rand() % (1 + 1 - 0) + 0;
            ij = find_enemy(game, ij);
        }
        game.enemy[ij.i][ij.j].pos = (sfVector2f){800, 800};
        sfSprite_setPosition(game.enemy[ij.i][ij.j].sprite,
        game.enemy[ij.i][ij.j].pos);
        sfClock_restart(game.clock);
    }
    return (game);
}