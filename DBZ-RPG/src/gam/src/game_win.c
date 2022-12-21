/*
** EPITECH PROJECT, 2020
** game win
** File description:
** game win
*/

#include "../include/game.h"

static t_rpg gamewin_click(t_rpg game, tex_font f_t)
{
    if (button_click(game.mouse, game.b_yes)) {
        game.sound ? sfSound_play(game.click.sound) : 0;
        game = re_init(game, f_t);
        game.id = menu_id;
    }
    if (button_click(game.mouse, game.b_no)) {
        game.sound ? sfSound_play(game.click.sound) : 0;
        game.id = quit_id;
    }
    return (game);
}

static t_rpg gamewin_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = gamewin_click(game, f_t);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game.b_yes = button_effect(game.mouse, game.b_yes);
    game.b_no = button_effect(game.mouse, game.b_no);
    return (game);
}

static t_rpg game_win_buttons(t_rpg game)
{
    game.b_win.pos = (sfVector2f){150, 100};
    game.b_again.pos = (sfVector2f){300, 350};
    game.b_yes.pos = (sfVector2f){350, 500};
    game.b_no.pos = (sfVector2f){805, 500};
    sfText_setPosition(game.b_win.text, game.b_win.pos);
    sfText_setPosition(game.b_again.text, game.b_again.pos);
    sfText_setPosition(game.b_yes.text, game.b_yes.pos);
    sfText_setPosition(game.b_no.text, game.b_no.pos);
    return (game);
}

t_rpg game_win(t_rpg game, tex_font f_t)
{
    game = game_win_buttons(game);
    game = gamewin_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_win.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_again.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_yes.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_no.text, NULL);
    return (game);
}