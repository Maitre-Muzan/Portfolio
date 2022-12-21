/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** main
*/

#include "gam/include/game.h"

t_rpg rpg_test(t_rpg game, tex_font f_t)
{
    sfRenderWindow_setMouseCursorVisible(game.win, sfTrue);
    re_initialization(&game.texture, &game.goku);
    menu_window(&game.screen, &game.texture);
    text_menu(&game.screen);
    filled_cine(&game.texture);
    event_menu(&game.screen, &game.texture, &game.goku);
    game.id = 42;
    return (game);
}

int main(int ac, char **av)
{
    tex_font f_t = init_font_tex(f_t);
    t_rpg game;

    game.win = window_create("MY_RPG", sfTrue);
    srand(rand_seed());
    if (!game.win)
        return (84);
    my_rpg(game, f_t);
    return (0);
}
