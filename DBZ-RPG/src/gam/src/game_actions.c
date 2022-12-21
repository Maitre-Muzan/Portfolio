/*
** EPITECH PROJECT, 2020
** game_2
** File description:
** game 2
*/

#include "../include/game.h"


static t_rpg end_game(t_rpg game)
{
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++) {
            if (game.enemy[i][j].pos.x == -200 &&
            game.enemy[i][j].pos.y == -200 && game.enemy[i][j].alive) {
                game.id = game_over_id;
                game.sound ? sfMusic_play(game.game_over) : 0;
            }
        }
    }
    return (game);
}

t_rpg dead_end(t_rpg game, tex_font f_t)
{
    game = enemy_dead(game);
    game = all_dead(game);
    game = end_game(game);
    game = life_tower(game);
    game = tower_redef(game);
    return (game);
}

t_rpg game_set(t_rpg game, tex_font f_t)
{
    game = put_enemies(game);
    game.b_score.pos = (sfVector2f){900, 0};
    game.towers[0][0].pos = (sfVector2f){20, 150};
    game.towers[1][0].pos = (sfVector2f){20, 300};
    game.towers[2][0].pos = (sfVector2f){20, 450};
    game.towers[3][0].pos = (sfVector2f){20, 600};
    game = set_marker_position(game);
    for (int i = 0; i < tow_type; i++) {
        sfSprite_setPosition(game.towers[i][0].sprite, game.towers[i][0].pos);
        sfRenderWindow_drawSprite(game.win, game.towers[i][0].sprite, NULL);
        print_tower_price(game, game.towers[i][0], f_t);
    }
    sfRenderWindow_drawSprite(game.win, game.map.sprite, NULL);
    return (game);
}

t_rpg game_anime(t_rpg game, tex_font f_t)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 1; j < tow_nb; j++) {
            sfSprite_setPosition(game.towers[i][j].sprite,
                                    game.towers[i][j].pos);
            sfRenderWindow_drawSprite(game.win, game.towers[i][j].sprite, NULL);
            game = display_int(game,
                (t_numb){game.towers[i][j].life, 20, sfRed},
                (sfVector2f){game.towers[i][j].pos.x + 10,
                game.towers[i][j].pos.y + 20}, f_t);
        }
    }
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++)
            game.enemy[i][j] = anime_enemy(game.enemy[i][j]);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(game.clock2)) > 0.5f) {
        game = towers_attack(game, f_t);
        sfClock_restart(game.clock2);
    }
    return (game);
}