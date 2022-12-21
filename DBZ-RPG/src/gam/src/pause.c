/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/

#include "../include/game.h"

static t_rpg pause_click(t_rpg game, tex_font f_t)
{
    if (button_click(game.mouse, game.b_resume)) {
        game.id = new_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_menu)) {
        game = re_init(game, f_t);
        game.id = menu_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
        switch_music(game, sfFalse);
    }
    if (button_click(game.mouse, game.b_quit)) {
        game.id = quit_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    return (game);
}

static t_rpg pause_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = pause_click(game, f_t);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game.b_quit = button_effect(game.mouse, game.b_quit);
    game.b_resume = button_effect(game.mouse, game.b_resume);
    game.b_menu = button_effect(game.mouse, game.b_menu);
    return (game);
}

static t_rpg pause_buttons(t_rpg game)
{
    game.b_title.pos = (sfVector2f){200, 100};
    game.b_quit.pos = (sfVector2f){200, 500};
    game.b_resume.pos = (sfVector2f){200, 300};
    game.b_menu.pos = (sfVector2f){200, 400};
    sfText_setPosition(game.b_title.text, game.b_title.pos);
    sfText_setPosition(game.b_quit.text, game.b_quit.pos);
    sfText_setPosition(game.b_resume.text, game.b_resume.pos);
    sfText_setPosition(game.b_menu.text, game.b_menu.pos);
    return (game);
}

t_rpg pause_game(t_rpg game, tex_font f_t)
{
    game = pause_buttons(game);
    game = pause_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_title.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_quit.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_resume.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_menu.text, NULL);
    sfRenderWindow_drawSprite(game.win, game.logo.sprite, NULL);
    return (game);
}