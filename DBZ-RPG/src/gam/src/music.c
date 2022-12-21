/*
** EPITECH PROJECT, 2020
** music
** File description:
** music
*/

#include "../include/game.h"

int switch_music(t_rpg game, sfBool bool)
{
    if (bool) {
        sfMusic_pause(game.menu_music);
        sfMusic_play(game.game_music);
    } else {
        sfMusic_pause(game.game_music);
        sfMusic_play(game.menu_music);
    }
    return (0);
}

void destroy_music(t_rpg game)
{
    sfMusic_destroy(game.menu_music);
    sfMusic_destroy(game.game_music);
    sfMusic_destroy(game.game_over);
    sfMusic_destroy(game.game_win);
}

t_rpg init_music(t_rpg game)
{
    game.menu_music = sfMusic_createFromFile(MUSIC1);
    game.game_music = sfMusic_createFromFile(MUSIC2);
    game.game_over = sfMusic_createFromFile(M_OVER);
    game.game_win = sfMusic_createFromFile(M_WIN);
    return (game);
}