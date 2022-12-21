/*
** EPITECH PROJECT, 2020
** defender game
** File description:
** defender game
*/

#include "../include/game.h"

static t_rpg (*interface[8])(t_rpg, tex_font) = {
    menu, play_game, pause_game, opt_game, help,
    rpg_test, game_over, game_win
};

int my_rpg(t_rpg game, tex_font f_t)
{
    game = init_game(game, f_t);
    sfMusic_play(game.menu_music);
    sfMusic_setLoop(game.menu_music, sfTrue);
    sfMusic_setVolume(game.menu_music, 50);
    sfMusic_setLoop(game.game_music, sfTrue);
    while (sfRenderWindow_isOpen(game.win)) {
        game = cursor(game);
        sfRenderWindow_clear(game.win, sfBlack);
        sfRenderWindow_drawSprite(game.win, game.menu_bg.sprite, NULL);
        if (game.id >= 0 && game.id <= 8) {
            if (game.id == 5)
                sfMusic_setVolume(game.menu_music, 0);
            game = interface[game.id](game, f_t);
        } else
            break;
        sfRenderWindow_drawSprite(game.win, game.cursor.sprite, NULL);
        sfRenderWindow_display(game.win);
    }
    destroy_game(game, f_t);
    return (0);
}

int menu_st(int ac, char **av)
{
    tex_font f_t = init_font_tex(f_t);
    t_rpg game;

    game.win = window_create("MY_DEFENDER", sfTrue);
    srand(rand_seed());
    if (!game.win)
        return (84);
    my_rpg(game, f_t);
    return (0);
}
