/*
** EPITECH PROJECT, 2020
** dead enemy
** File description:
** dead enemy
*/

#include "../include/game.h"

t_rpg all_dead(t_rpg game)
{
    int count = 0;

    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            if (game.enemy[i][j].alive == sfFalse)
                count++;
        }
    }
    if (count == (nb_enemy * type_enemy)) {
        game.id = game_win_id;
        game.sound ? sfMusic_play(game.game_win) : 0;
    }
    return (game);
}

t_rpg enemy_dead(t_rpg game)
{
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            if (game.enemy[i][j].life <= 0 && game.enemy[i][j].alive) {
                game.enemy[i][j].alive = sfFalse;
                game.enemy[i][j].pos = (sfVector2f){-300, -300};
                game.money += 100;
                game.score += 250;
                sfSprite_setPosition(game.enemy[i][j].sprite,
                    (sfVector2f){-300, -300});
            }
        }
    }
    return (game);
}