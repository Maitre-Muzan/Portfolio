/*
** EPITECH PROJECT, 2020
** options
** File description:
** options
*/

#include "../include/game.h"

static t_rpg opt_click(t_rpg game)
{
    sfSoundStatus stat =  sfMusic_getStatus(game.menu_music);

    if (button_click(game.mouse, game.b_back)) {
        game.id = menu_id;
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_fullscreen)) {
        game = redefine_window(game);
        game.sound ? sfSound_play(game.click.sound) : 0;
    }
    if (button_click(game.mouse, game.b_sound)) {
        game.sound = (game.sound ? sfFalse : sfTrue);
        game.sound ? sfSound_play(game.click.sound) : 0;
        if (game.sound == sfFalse && stat == sfPlaying)
            sfMusic_pause(game.menu_music);
        else if (game.sound && (stat == sfPaused || stat == sfStopped))
            sfMusic_play(game.menu_music);
    }
    return (game);
}

static t_rpg opt_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            break;
            case sfEvtMouseButtonPressed: game = opt_click(game);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game.b_fullscreen = button_effect(game.mouse, game.b_fullscreen);
    game.b_sound = button_effect(game.mouse, game.b_sound);
    game.b_back = button_effect(game.mouse, game.b_back);
    return (game);
}

static void on_off(sfRenderWindow **win, t_button opt, t_button button)
{
    sfText_setPosition(button.text, (sfVector2f){opt.pos.x + 400, opt.pos.y});
    sfRenderWindow_drawText(*win, button.text, NULL);
}

static t_rpg opt_buttons(t_rpg game)
{
    game.b_title.pos = (sfVector2f){200, 100};
    game.b_fullscreen.pos = (sfVector2f){200, 400};
    game.b_sound.pos = (sfVector2f){200, 300};
    game.b_back.pos = (sfVector2f){200, 500};
    sfText_setPosition(game.b_title.text, game.b_title.pos);
    sfText_setPosition(game.b_fullscreen.text, game.b_fullscreen.pos);
    sfText_setPosition(game.b_sound.text, game.b_sound.pos);
    sfText_setPosition(game.b_back.text, game.b_back.pos);
    game.full ? on_off(&game.win, game.b_fullscreen, game.b_on) :
        on_off(&game.win, game.b_fullscreen, game.b_off);
    game.sound ? on_off(&game.win, game.b_sound, game.b_on) :
        on_off(&game.win, game.b_sound, game.b_off);
    return (game);
}

t_rpg opt_game(t_rpg game, tex_font f_t)
{
    game = opt_buttons(game);
    game = opt_event(game, f_t);
    sfRenderWindow_drawText(game.win, game.b_title.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_fullscreen.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_sound.text, NULL);
    sfRenderWindow_drawText(game.win, game.b_back.text, NULL);
    sfRenderWindow_drawSprite(game.win, game.logo.sprite, NULL);
    return (game);
}