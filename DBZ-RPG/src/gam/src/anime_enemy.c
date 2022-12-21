/*
** EPITECH PROJECT, 2020
** anime ennemy
** File description:
** anime enemy
*/

#include "../include/game.h"

t_rpg draw_enemy(t_rpg game, tex_font f_t)
{
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            if (game.enemy[i][j].alive)
                sfRenderWindow_drawSprite(game.win,
                    game.enemy[i][j].sprite, NULL);
        }
    }
    return (game);
}

t_enemy animes_right(t_enemy enemy, int *start, int *end)
{
    *end = enemy.walk_right[1];
    *start = enemy.walk_right[0];
    if (enemy.rect.left < (enemy.walk_right[0] * enemy.inc)
    || enemy.rect.left > (enemy.walk_right[1] * enemy.inc))
        enemy.rect.left = enemy.walk_right[0] * enemy.inc;
    return (enemy);
}

t_enemy animes_front(t_enemy enemy, int *start, int *end)
{
    *end = enemy.walk_front[1];
    *start = enemy.walk_front[0];
    if (enemy.rect.left < (enemy.walk_front[0] * enemy.inc)
    || enemy.rect.left > (enemy.walk_front[1] * enemy.inc))
        enemy.rect.left = enemy.walk_front[0] * enemy.inc;
    return (enemy);
}

t_enemy animes_left(t_enemy enemy, int *start, int *end)
{
    *end = enemy.walk_left[1];
    *start = enemy.walk_left[0];
    if (enemy.rect.left < (enemy.walk_left[0] * enemy.inc)
    || enemy.rect.left > (enemy.walk_left[1] * enemy.inc))
        enemy.rect.left = enemy.walk_left[0] * enemy.inc;
    return (enemy);
}

t_enemy anime_enemy(t_enemy enemy)
{
    int start = 0;
    int end = 0;

    if (enemy.section == 0)
        enemy = animes_front(enemy, &start, &end);
    if (enemy.section == 1)
        enemy = animes_right(enemy, &start, &end);
    if (enemy.section == 2)
        enemy = animes_left(enemy, &start, &end);
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy.clock)) > 1.0f) {
        if (enemy.rect.left == end * enemy.inc)
            enemy.rect.left = start * enemy.inc;
        else
            enemy.rect.left += enemy.inc;
        sfClock_restart(enemy.clock);
        sfSprite_setTextureRect(enemy.sprite, enemy.rect);
    }
    return (enemy);
}