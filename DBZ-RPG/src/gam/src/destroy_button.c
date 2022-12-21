/*
** EPITECH PROJECT, 2020
** destroy button
** File description:
** destroy button
*/

#include "../include/game.h"

t_rpg destroy_button1(t_rpg game)
{
    sfText_destroy(game.b_score.text);
    sfText_destroy(game.b_again.text);
    sfText_destroy(game.b_back.text);
    sfText_destroy(game.b_continue.text);
    sfText_destroy(game.b_frame.text);
    sfText_destroy(game.b_fullscreen.text);
    sfText_destroy(game.b_h.text);
    sfText_destroy(game.b_help.text);
    sfText_destroy(game.b_high.text);
    sfText_destroy(game.b_menu.text);
    sfText_destroy(game.b_new.text);
    sfText_destroy(game.b_no.text);
    sfText_destroy(game.b_off.text);
    return (game);
}

t_rpg destroy_button2(t_rpg game)
{
    sfText_destroy(game.b_play.text);
    sfText_destroy(game.b_quit.text);
    sfText_destroy(game.b_resume.text);
    sfText_destroy(game.b_sound.text);
    sfText_destroy(game.b_title.text);
    sfText_destroy(game.b_win.text);
    sfText_destroy(game.b_yes.text);
    sfText_destroy(game.b_on.text);
    sfText_destroy(game.b_opt.text);
    sfText_destroy(game.b_over.text);
    return (game);
}

t_rpg destroy_button(t_rpg game)
{
    game = destroy_button1(game);
    game = destroy_button2(game);
    return (game);
}