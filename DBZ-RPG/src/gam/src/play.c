/*
** EPITECH PROJECT, 2020
** play
** File description:
** play
*/

#include "../include/game.h"

static t_rpg play_click(t_rpg game)
{
    if (button_click(game.mouse, game.b_back)) {
        game.id = menu_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_new)) {
        game.id = new_id;
    }
    return (game);
}

static t_rpg play_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = play_click(game);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game.b_back = button_effect(game.mouse, game.b_back);
    game.b_new = button_effect(game.mouse, game.b_new);
    return (game);
}

static t_rpg play_buttons(t_rpg game)
{
    game.b_title.pos = (sfVector2f){200, 100};
    game.b_back.pos = (sfVector2f){200, 600};
    game.b_new.pos = (sfVector2f){200, 300};
    game.b_continue.pos = (sfVector2f){200, 400};
    game.b_back.pos = (sfVector2f){200, 500};
    sfText_setPosition(game.b_title.text, game.b_title.pos);
    sfText_setPosition(game.b_back.text, game.b_back.pos);
    sfText_setPosition(game.b_new.text, game.b_new.pos);
    sfText_setPosition(game.b_continue.text, game.b_continue.pos);
    return (game);
}

t_rpg play_game(t_rpg game, tex_font f_t)
{
    game = play_buttons(game);
    game = play_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_title.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_back.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_new.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_continue.text, NULL);
    sfRenderWindow_drawSprite(game.win, game.logo.sprite, NULL);
    return (game);
}
