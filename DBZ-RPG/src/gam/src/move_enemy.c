/*
** EPITECH PROJECT, 2020
** move_enemy
** File description:
** move enemy
*/

#include "../include/game.h"

t_enemy move_left_right(t_enemy enemy)
{
    if ((enemy.pos.y == 585 && enemy.pos.x <= 800 && enemy.pos.x >= 360) ||
    (enemy.pos.y == 280 && enemy.pos.x <= 1121 && enemy.pos.x >= 770)) {
        enemy.pos.x -= 1;
        enemy.section = 2;
    }
    if (enemy.pos.y == 425 && enemy.pos.x >= 359 && enemy.pos.x <= 1120)  {
        enemy.pos.x += 1;
        enemy.section = 1;
    }
    return (enemy);
}

t_enemy move_enemy(t_enemy enemy)
{
    if ((enemy.pos.y <= 800 && enemy.pos.y > 585 && enemy.pos.x == 800) ||
    (enemy.pos.y <= 585 && enemy.pos.y > 425 && enemy.pos.x == 359) ||
    (enemy.pos.y <= 425 && enemy.pos.y > 280 && enemy.pos.x == 1121) ||
    (enemy.pos.y <= 280 && enemy.pos.y > 140 && enemy.pos.x == 769)) {
        enemy.pos.y -= 1;
        enemy.section = 0;
    }
    enemy = move_left_right(enemy);
    if (enemy.pos.y == 140) {
        enemy.pos.x = -200;
        enemy.pos.y = -200;
    }
    sfSprite_setPosition(enemy.sprite, enemy.pos);
    return (enemy);
}