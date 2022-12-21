/*
** EPITECH PROJECT, 2020
** game over
** File description:
** game over
*/

#include "../include/game.h"

static t_rpg gameover_click(t_rpg game, tex_font f_t)
{
    if (button_click(game.mouse, game.b_yes)) {
        game.sound ? sfSound_play(game.click.sound) : 0;
        game = re_init(game, f_t);
        game.id = menu_id;
    }
    if (button_click(game.mouse, game.b_no)) {
        game.id = quit_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    return (game);
}

static t_rpg gameover_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = gameover_click(game, f_t);
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

static t_rpg game_over_buttons(t_rpg game)
{
    game.b_over.pos = (sfVector2f){300, 100};
    game.b_again.pos = (sfVector2f){300, 350};
    game.b_yes.pos = (sfVector2f){350, 500};
    game.b_no.pos = (sfVector2f){805, 500};
    sfText_setPosition(game.b_over.text, game.b_over.pos);
    sfText_setPosition(game.b_again.text, game.b_again.pos);
    sfText_setPosition(game.b_yes.text, game.b_yes.pos);
    sfText_setPosition(game.b_no.text, game.b_no.pos);
    return (game);
}

t_rpg game_over(t_rpg game, tex_font f_t)
{
    game = game_over_buttons(game);
    game = gameover_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_over.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_again.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_yes.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_no.text, NULL);
    return (game);
}