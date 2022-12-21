/*
** EPITECH PROJECT, 2020
** helpù
** File description:
** help
*/

#include "../include/game.h"

static t_rpg help_click(t_rpg game)
{
    if (button_click(game.mouse, game.b_back)) {
        game.id = menu_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    return (game);
}

static t_rpg help_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = help_click(game);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game.b_back = button_effect(game.mouse, game.b_back);
    return (game);
}

static t_rpg help_buttons(t_rpg game)
{
    game.b_back.pos = (sfVector2f){100, 600};
    game.b_h.pos = (sfVector2f){100, 100};
    sfText_setPosition(game.b_back.text, game.b_back.pos);
    sfText_setPosition(game.b_h.text, game.b_h.pos);
    return (game);
}

t_rpg help(t_rpg game, tex_font f_t)
{
    game = help_buttons(game);
    game = help_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_back.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_h.text, NULL);
    return (game);
}