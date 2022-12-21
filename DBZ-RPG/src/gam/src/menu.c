/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "../include/game.h"

static t_rpg menu_click(t_rpg game)
{
    if (button_click(game.mouse, game.b_play)) {
        game.id = play_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_opt)) {
        game.id = opt_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_quit)) {
        game.id = quit_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_help)) {
        game.id = help_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    return (game);
}

static t_rpg menu_click_2(t_rpg game)
{
    if (button_click(game.mouse, game.b_avatar)) {
        game.id = avatar_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
}

static t_rpg menu_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = menu_click(game);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
        }
    }
    game.b_play = button_effect(game.mouse, game.b_play);
    game.b_opt = button_effect(game.mouse, game.b_opt);
    game.b_avatar = button_effect(game.mouse, game.b_avatar);
    game.b_help = button_effect(game.mouse, game.b_help);
    game.b_quit = button_effect(game.mouse, game.b_quit);
    return (game);
}

static t_rpg menu_button_positions(t_rpg game)
{
    game.b_title.pos = (sfVector2f){200, 100};
    game.b_play.pos = (sfVector2f){200, 300};
    game.b_opt.pos = (sfVector2f){200, 380};
    game.b_avatar.pos = (sfVector2f){200, 460};
    game.b_help.pos = (sfVector2f){200, 540};
    game.b_quit.pos = (sfVector2f){200, 620};
    sfText_setPosition(game.b_title.text, game.b_title.pos);
    sfText_setPosition(game.b_play.text, game.b_play.pos);
    sfText_setPosition(game.b_opt.text, game.b_opt.pos);
    sfText_setPosition(game.b_avatar.text, game.b_avatar.pos);
    sfText_setPosition(game.b_help.text, game.b_help.pos);
    sfText_setPosition(game.b_quit.text, game.b_quit.pos);
    return (game);
}

t_rpg menu(t_rpg game, tex_font f_t)
{
    game = menu_button_positions(game);
    game = menu_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_title.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_play.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_opt.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_avatar.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_help.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_quit.text, NULL);
    sfRenderWindow_drawSprite(game.win, game.logo.sprite, NULL);
    return (game);
}
